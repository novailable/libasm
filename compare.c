#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

size_t ft_strlen(const char *s);

static double diff_ns(struct timespec a, struct timespec b)
{
    return (double)(b.tv_sec - a.tv_sec) * 1e9 +
           (double)(b.tv_nsec - a.tv_nsec);
}

int main(void)
{
    const char *s = "Hi hello this";
    const long iterations = 10000000;
    struct timespec start, end;
    volatile size_t result = 0;

    if (clock_gettime(CLOCK_MONOTONIC_RAW, &start) != 0) {
        perror("clock_gettime");
        return 1;
    }

    for (long i = 0; i < iterations; i++) {
        result += ft_strlen(s);
    }

    if (clock_gettime(CLOCK_MONOTONIC_RAW, &end) != 0) {
        perror("clock_gettime");
        return 1;
    }

    printf("ft_strlen: %.0f ns\n", diff_ns(start, end));

    if (clock_gettime(CLOCK_MONOTONIC_RAW, &start) != 0) {
        perror("clock_gettime");
        return 1;
    }

    for (long i = 0; i < iterations; i++) {
        result += strlen(s);
    }

    if (clock_gettime(CLOCK_MONOTONIC_RAW, &end) != 0) {
        perror("clock_gettime");
        return 1;
    }

    printf("strlen:    %.0f ns\n", diff_ns(start, end));

    if (result == 0)
        printf("%zu\n", result);

    return 0;
}