#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(const char *s); // from your .o

static double diff_ns(struct timespec a, struct timespec b)
{
    return (b.tv_sec - a.tv_sec) * 1e9 +
           (b.tv_nsec - a.tv_nsec);
}

#define BENCH(fn, arg, iters) ( \
    {   \
        struct timespec _s, _e; \
        clock_gettime(CLOCK_MONOTONIC_RAW, &_s);    \
        for (long _i = 0; _i < (iters); _i++)   \
            (fn)(arg);   \
        clock_gettime(CLOCK_MONOTONIC_RAW, &_e);    \
        (long)diff_ns(_s, _e);  \
    }   \
)

#define CHECK(fn1, fn2, in)  (\
    {   \
        printf("ft_strlen time\t: %.0ld ns\n", BENCH(fn1, in, 100000));  \
        printf("strlen time\t: %.0ld ns\n", BENCH(fn2, in, 100000));  \
    }   \
)

long	compute_timestamp(void (*func)(), char *argv)
{
	struct timespec start, end;

    long iterations = 10000000;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    for (long i = 0; i < iterations; i++) {
        func(argv);
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	return (diff_ns(start, end));
}


int	main(void)
{
    const char *in = "Hello world this is a test string";
    
    if (ft_strlen(in) != strlen(in))
        return (printf("ft_strlen failed!"), 1);
	CHECK(ft_strlen, strlen, in);
    return 0;
}
