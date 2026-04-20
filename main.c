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
    const char *s = "Hello world this is a test string";

	printf("ft_strlen time\t: %.0ld ns\n", compute_timestamp(ft_strlen, s));
    printf("strlen time\t: %.0ld ns\n", compute_timestamp(strlen, s));   
    return 0;
}
