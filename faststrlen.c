#include <stddef.h>
#include <stdint.h>

static int has_zero_byte(uint64_t x)
{
    return ((x - 0x0101010101010101ULL) &
            ~x &
            0x8080808080808080ULL) != 0;
}

size_t fast_strlen_c(const char *s)
{
    const char *p = s;

    while ((uintptr_t)p & 7)
    {
        if (*p == '\0')
            return (size_t)(p - s);
        p++;
    }

    for (;;)
    {
        uint64_t x = *(const uint64_t *)p;
        uint64_t m = zero_byte_mask(x);

        if (m)
        {
            unsigned byte_index = (unsigned)__builtin_ctzll(m) / 8;
            return (size_t)(p - s) + byte_index;
        }

        p += 8;
    }
}
