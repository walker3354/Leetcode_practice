#include <stdlib.h>
#include <string.h>

int max_num(int a, int b) {
    if (a >= b) return a;
    return b;
}

int lengthOfLongestSubstring(char* s) {
    int char_map[128];
    int begin = 0, result = 0;
    int s_len = strlen(s);
    memset(char_map, -1, sizeof(char_map));

    for (int i = 0; i < s_len; i++) {
        int last_appear = char_map[(int)s[i]];
        if (last_appear >= begin) {
            result = max_num(result, (i - begin));
            begin = last_appear + 1;
        }
        char_map[(int)s[i]] = i;
    }
    result = max_num(result, (s_len - begin));
    return result;
}