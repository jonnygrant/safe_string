// gcc -std=c17 -Wall -Wextra -O2 -o main main.c stringcopy.c

#include "stringcopy.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char dest[20];
    const char src[] = "hello world";
    size_t dest_written;
    int result = stringcopy(dest, src, 20, sizeof(src), &dest_written);
    printf("stringcopy params: src size: %zu dest size: %zu\n", sizeof(src), sizeof(dest));

    printf("stringcopy result: %d dest_written: %zu dest[%s]\n", result, dest_written, dest);
    if(result != 0) printf("error: [%s]\n", strerror(result));
}
