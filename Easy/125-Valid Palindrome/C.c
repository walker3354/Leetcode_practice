#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool is_ascii_alnum(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

static char to_ascii_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char)(c + ('a' - 'A'));
    }
    return c;
}

bool isPalindrome(char* s) {
    if (s == NULL) return true;

    int s_len = strlen(s);
    if (s_len == 0 || s_len == 1) return true;

    int left = 0, right = s_len - 1;
    while (left < right) {
        while (left < right && !is_ascii_alnum(s[left])) {
            left++;
        }
        while (left < right && !is_ascii_alnum(s[right])) {
            right--;
        }

        if (to_ascii_lower(s[left]) != to_ascii_lower(s[right])) return false;

        left++;
        right--;
    }

    return true;
}
