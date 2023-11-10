#include "stringcopy.h"

/* for strncpy */
#define _POSIX_C_SOURCE 200809L

#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

//#define STRING_DEBUG
#ifdef STRING_DEBUG
#define DEBUG_PRINT(...)    printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

int stringcopy(char * dest, const char * const src, const size_t dest_max_size, const size_t src_max_size, size_t * const dest_written)
{
    int result = 0;

    if(dest == NULL || src == NULL || dest_written == NULL)
    {
        DEBUG_PRINT("stringcopy EFAULT %p %p %p\n", dest, src, dest_written);
        result = EFAULT;
    }
    else if((src_max_size > INT_MAX) || (src_max_size > INT_MAX))
    {
        result = EMSGSIZE;
    }
    else if(src_max_size > dest_max_size)
    {
        DEBUG_PRINT("stringcopy ENOSPC %zu %zu\n", src_max_size, dest_max_size);
        result = ENOSPC;
    }
    else
    {
        const size_t len = strnlen(src, src_max_size) + 1;
        if(len > dest_max_size)
        {
            result = ERANGE;
        }
        else
        {
            int copy_size = snprintf(dest, dest_max_size, "%s", src);
            if(copy_size < 0)
            {
                result = EOVERFLOW;

                /* Ensure NUL terminated */
                dest[0] = '\0';
            }
            else
            {
                /* Increment to count for the NUL terminator */
                *dest_written = ((size_t)copy_size + 1);
            }
        }
    }

    return result;
}
