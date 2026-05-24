#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    if (s == NULL) return 0;

    int s_len = strlen(s);
    if (s_len == 0) return 0;
    if (s_len == 1) return 1;

    int result = 0;
    int begin = 0;
    int* record_map = malloc(256 * sizeof(int));
    if (record_map == NULL) return 0;

    memset(record_map, -1, sizeof(int) * 256);

    for (int i = 0; i < s_len; i++) {
        unsigned char c = (unsigned char)s[i];
        if (record_map[c] < begin) {
            int len = (i - begin) + 1;
            result = result > len ? result : len;
        } else {
            begin = record_map[c] + 1;
        }
        record_map[c] = i;
    }

    free(record_map);
    return result;
}
