#include <stdlib.h>

void* my_memcpy(void* dest, const void* src, size_t n);
void* my_memmove(void* dest, const void* src, size_t n);

void* my_memmove(void* dest, const void* src, size_t n) {
    if (dest == NULL || src == NULL) return NULL;

    const char* c_src = (const char*)src;
    char* c_dest = (char*)dest;
    if (c_src > c_dest) {
        for (int i = 0; i < n; i++) {
            c_dest[i] = c_src[i];
        }
    } else if (c_dest > c_src) {
        for (int i = n - 1; i >= 0; i--) {
            c_dest[i] = c_src[i];
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