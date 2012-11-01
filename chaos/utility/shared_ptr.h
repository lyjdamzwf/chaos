#ifndef _CHAOS_SHAREDPTR_H_
#define _CHAOS_SHAREDPTR_H_

#include <stdint.h>

#include <algorithm>

#include <chaos/utility/memory.h>

namespace chaos
{

namespace utility
{

class ref_counter_t
{
public:
	ref_counter_t(): m_cnt(1)
	{
	}

	void duplicate()
	{
		++m_cnt;
	}

	int release()
	{
		return --m_cnt;
	}
	
	int ref_count() const
	{
		return m_cnt;
	}

private:
	uint32_t            m_cnt;
};

template <class C>
class destroy_policy_t
{
public:
	static void release(C* obj_)
	{
        chaos::utility::destroy(obj_);
	}
};

template <class C>
class delete_policy_t
{
public:
	static void release(C* obj_)
	{
		delete obj_;
	}
};

template <class C>
class delete_arr_policy_t
{
public:
	static void release(C* arr_)
	{
		delete [] arr_;
	}
};

template <class C, class RC = ref_counter_t, class RP = delete_policy_t<C> >
class shared_ptr_t
{
public:
	shared_ptr_t(): m_counter_ptr(construct<RC>()), m_ptr(0)
	{
	}

	shared_ptr_t(C* ptr): m_counter_ptr(construct<RC>()), m_ptr(ptr)
	{
	}

	template <class Other, class OtherRP> 
	shared_ptr_t(const shared_ptr_t<Other, RC, OtherRP>& ptr_): m_counter_ptr(ptr_.m_counter_ptr), m_ptr(const_cast<Other*>(ptr_.get()))
	{
		m_counter_ptr->duplicate();
	}

	shared_ptr_t(const shared_ptr_t& ptr_): m_counter_ptr(ptr_.m_counter_ptr), m_ptr(ptr_.m_ptr)
	{
		m_counter_ptr->duplicate();
	}

	~shared_ptr_t()
	{
		release();
	}

	shared_ptr_t& assign(C* ptr_)
	{
		if (get() != ptr_)
		{
			RC* tmp_ptr = construct<RC>();
			release();
			m_counter_ptr = tmp_ptr;
			m_ptr = ptr_;
		}
		return *this;
	}
	
	shared_ptr_t& assign(const shared_ptr_t& ptr_)
	{
		if (&ptr_ != this)
		{
			shared_ptr_t tmp(ptr_);
			swap(tmp);
		}
		return *this;
	}
	
	template <class Other, class OtherRP>
	shared_ptr_t& assign(const shared_ptr_t<Other, RC, OtherRP>& ptr_)
	{
		if (ptr_.get() != m_ptr)
		{
			shared_ptr_t tmp(ptr_);
			swap(tmp);
		}
		return *this;
	}

	shared_ptr_t& operator = (C* ptr_)
	{
		return assign(ptr_);
	}

	shared_ptr_t& operator = (const shared_ptr_t& ptr_)
	{
		return assign(ptr_);
	}

	template <class Other, class OtherRP>
	shared_ptr_t& operator = (const shared_ptr_t<Other, RC, OtherRP>& ptr_)
	{
		return assign<Other>(ptr_);
	}

	void swap(shared_ptr_t& ptr_)
	{
		std::swap(m_ptr, ptr_.m_ptr);
		std::swap(m_counter_ptr, ptr_.m_counter_ptr);
	}

	template <class Other> 
	shared_ptr_t<Other, RC, RP> cast() const
		/// Casts the shared_ptr_t via a dynamic cast to the given type.
		/// Returns an shared_ptr_t containing NULL if the cast fails.
		/// Example: (assume class Sub: public Super)
		///    shared_ptr_t<Super> super(new Sub());
		///    shared_ptr_t<Sub> sub = super.cast<Sub>();
		///    poco_assert (sub.get());
	{
		Other* other_ptr = dynamic_cast<Other*>(m_ptr);
		if (other_ptr)
			return shared_ptr_t<Other, RC, RP>(m_counter_ptr, other_ptr);
		return shared_ptr_t<Other, RC, RP>();
	}

	template <class Other> 
	shared_ptr_t<Other, RC, RP> unsafeCast() const
		/// Casts the shared_ptr_t via a static cast to the given type.
		/// Example: (assume class Sub: public Super)
		///    shared_ptr_t<Super> super(new Sub());
		///    shared_ptr_t<Sub> sub = super.unsafeCast<Sub>();
		///    poco_assert (sub.get());
	{
		Other* other_ptr = static_cast<Other*>(m_ptr);
		return shared_ptr_t<Other, RC, RP>(m_counter_ptr, other_ptr);
	}

	C* operator -> ()
	{
		return deref();
	}

	const C* operator -> () const
	{
		return deref();
	}

	C& operator * ()
	{
		return *deref();
	}

	const C& operator * () const
	{
		return *deref();
	}

	C* get()
	{
		return m_ptr;
	}

	const C* get() const
	{
		return m_ptr;
	}

	operator C* ()
	{
		return m_ptr;
	}
	
	operator const C* () const
	{
		return m_ptr;
	}

	bool operator ! () const
	{
		return m_ptr == 0;
	}

	bool isNull() const
	{
		return m_ptr == 0;
	}

	bool operator == (const shared_ptr_t& ptr_) const
	{
		return get() == ptr_.get();
	}

	bool operator == (const C* ptr_) const
	{
		return get() == ptr_;
	}

	bool operator == (C* ptr_) const
	{
		return get() == ptr_;
	}

	bool operator != (const shared_ptr_t& ptr_) const
	{
		return get() != ptr_.get();
	}

	bool operator != (const C* ptr_) const
	{
		return get() != ptr_;
	}

	bool operator != (C* ptr_) const
	{
		return get() != ptr_;
	}

	bool operator < (const shared_ptr_t& ptr_) const
	{
		return get() < ptr_.get();
	}

	bool operator < (const C* ptr_) const
	{
		return get() < ptr_;
	}

	bool operator < (C* ptr_) const
	{
		return get() < ptr_;
	}

	bool operator <= (const shared_ptr_t& ptr_) const
	{
		return get() <= ptr_.get();
	}

	bool operator <= (const C* ptr_) const
	{
		return get() <= ptr_;
	}

	bool operator <= (C* ptr_) const
	{
		return get() <= ptr_;
	}

	bool operator > (const shared_ptr_t& ptr_) const
	{
		return get() > ptr_.get();
	}

	bool operator > (const C* ptr_) const
	{
		return get() > ptr_;
	}

	bool operator > (C* ptr_) const
	{
		return get() > ptr_;
	}

	bool operator >= (const shared_ptr_t& ptr_) const
	{
		return get() >= ptr_.get();
	}

	bool operator >= (const C* ptr_) const
	{
		return get() >= ptr_;
	}

	bool operator >= (C* ptr_) const
	{
		return get() >= ptr_;
	}
	
	int ref_count() const
	{
		return m_counter_ptr->ref_count();
	}

private:
	C* deref() const
	{
		return m_ptr;
	}

	void release()
	{
		int i = m_counter_ptr->release();
		if (i == 0)
		{
			RP::release(m_ptr);
			m_ptr = 0;

			chaos::utility::destroy(m_counter_ptr);
			m_counter_ptr = 0;
		}
	}

	shared_ptr_t(RC* counter_ptr_, C* ptr_): m_counter_ptr(counter_ptr_), m_ptr(ptr_)
		/// for cast operation
	{
		m_counter_ptr->duplicate();
	}

private:
	RC* m_counter_ptr;
	C*  m_ptr;

	template <class OtherC, class OtherRC, class OtherRP> friend class shared_ptr_t;
};


template <class C, class RC, class RP>
inline void swap(shared_ptr_t<C, RC, RP>& p1, shared_ptr_t<C, RC, RP>& p2)
{
	p1.swap(p2);
}

}

}

#endif // _CHAOS_SHAREDPTR_H_
