#ifndef _CHAOS_TEST_PERF_H_
#define _CHAOS_TEST_PERF_H_

#define WS_THREAD_NUM   8
#define USE_ATOMIC 1
#define VAL_PER_THREAD 1

//! yunjie: 这里不能用数组, 性能会被cache line影响
#if USE_ATOMIC
atomic_val_t<uint32_t> g_aval0;
atomic_val_t<uint32_t> g_aval1;
atomic_val_t<uint32_t> g_aval2;
atomic_val_t<uint32_t> g_aval3;
atomic_val_t<uint32_t> g_aval4;
atomic_val_t<uint32_t> g_aval5;
atomic_val_t<uint32_t> g_aval6;
atomic_val_t<uint32_t> g_aval7;
#else
volatile uint32_t g_val0 = 0;
volatile uint32_t g_val1 = 0;
volatile uint32_t g_val2 = 0;
volatile uint32_t g_val3 = 0;
volatile uint32_t g_val4 = 0;
volatile uint32_t g_val5 = 0;
volatile uint32_t g_val6 = 0;
volatile uint32_t g_val7 = 0;
#endif

void val_op(int index_)
{
    struct timeval begin_tv;
    gettimeofday(&begin_tv, NULL);

#if USE_ATOMIC
    atomic_val_t<uint32_t>*
#else
        volatile uint32_t*
#endif
        tmp_val;
    switch (index_)
    {
        case 0:
            tmp_val =
#if USE_ATOMIC
                &g_aval0;
#else
            &g_val0;
#endif
            break;
        case 1:
            tmp_val =
#if USE_ATOMIC
                &g_aval1;
#else
            &g_val1;
#endif
            break;
        case 2:
            tmp_val =
#if USE_ATOMIC
                &g_aval2;
#else
            &g_val2;
#endif
            break;
        case 3:
            tmp_val =
#if USE_ATOMIC
                &g_aval3;
#else
            &g_val3;
#endif
            break;
        case 4:
            tmp_val =
#if USE_ATOMIC
                &g_aval4;
#else
            &g_val4;
#endif
            break;
        case 5:
            tmp_val =
#if USE_ATOMIC
                &g_aval5;
#else
            &g_val5;
#endif
            break;
        case 6:
            tmp_val =
#if USE_ATOMIC
                &g_aval6;
#else
            &g_val6;
#endif
            break;
        case 7:
            tmp_val =
#if USE_ATOMIC
                &g_aval7;
#else
            &g_val7;
#endif
            break;
        default:
            tmp_val = NULL;
            break;
    }

    for (uint64_t i = 0; i < 100000000; ++i)
    {
        (*tmp_val)++;
        (*tmp_val)--;
    }

    struct timeval end_tv;
    gettimeofday(&end_tv, NULL);
    uint64_t cost_us = (end_tv.tv_sec - begin_tv.tv_sec) * 1000 * 1000 + (end_tv.tv_usec - begin_tv.tv_usec);

    printf("cost us:[%lu]\n", cost_us);
}

void test_atomic_perf()
{
    for (int i = 0; i < WSG().size(); ++i)
    {
        int arg;
#if VAL_PER_THREAD
        arg = i;
#else
        arg = 0;
#endif
        WSG()[i]->post(bindfunc(&val_op, arg));
    }
}

#endif //! _CHAOS_TEST_PERF_H_
