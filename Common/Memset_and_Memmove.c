#include <stdlib.h>
void* my_memmove(void* dest, const void* src, size_t n) {
    if (n == 0 || dest == NULL || src == NULL) return dest;

    char* c_dest = (char*)dest;
    const char* c_src = (const char*)src;

    if (c_src >= c_dest) {
        for (int i = 0; i < n; i++) {
            c_dest[i] = c_src[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            c_dest[n - 1 - i] = c_src[n - 1 - i];
        }
    }
    return dest;
}

void* my_memcpy(void* dest, const void* src, size_t n) {
    if (dest == NULL || src == NULL) return NULL;

    char* c_dest = (char*)dest;
    const char* c_src = (const char*)src;
    for (int i = 0; i < n; i++) {
        c_dest[i] = c_src[i];
    }
    return dest;
}