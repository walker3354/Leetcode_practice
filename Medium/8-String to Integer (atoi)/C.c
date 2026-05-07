#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int myAtoi(char* s) { // skip space + -, others break
    int s_len = strlen(s);
    bool sign = true; // true +, false -
    int result = 0, c_pos = 0;

    while (c_pos < s_len && s[c_pos] == ' ') { // skip space
        c_pos++;
    }

    if (s[c_pos] == '-') {
        sign = false;
        c_pos++;
    } else if (s[c_pos] == '+') {
        c_pos++;
    }

    while (c_pos < s_len && s[c_pos] >= '0' && s[c_pos] <= '9') {
        int num = s[c_pos++] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && num > 7)) { 
            return sign == true ? INT_MAX : INT_MIN;
        }
        result = result * 10 + num;
    }
    return sign == true ? result : -result;
}