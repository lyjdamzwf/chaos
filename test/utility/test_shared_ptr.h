#ifndef _CHAOS_TEST_UTILITY_H_
#define _CHAOS_TEST_UTILITY_H_

class obj_t
{
public:
    obj_t()
        :
            a(1121)
    {
        printf("obj_t construct\n");
    }

    ~obj_t()
    {
        printf("obj_t deconstruct\n");
    }

    void call()
    {
        printf("obj_t::call a:[%d]\n", a);
    }

private:
    int     a;
};

struct self_t
{
    self_t()
    {
        printf("self_t construct\n");
    }

    ~self_t()
    {
        printf("self_t deconstruct\n");
    }

    shared_ptr_t<self_t>            self_sptr;
};

void test_shared_ptr()
{
    shared_ptr_t<obj_t> sptr1;
    sptr1.dump();

    sptr1 = new obj_t;
    sptr1.dump();

    shared_ptr_t<obj_t> sptr2 = sptr1;

    //sptr1.reset();
    sptr1.dump();
    sptr2.dump();

    sptr1.reset();
    sptr1.dump();
    sptr2.dump();

    sptr1 = sptr2;
    sptr1.dump();
    sptr2.dump();

    shared_ptr_t<self_t> self = new self_t;
    self->self_sptr = self;
    self->self_sptr.reset();
    self.reset();

    printf("leave test_shared_ptr\n");
}

#endif //! _CHAOS_TEST_UTILITY_H_
