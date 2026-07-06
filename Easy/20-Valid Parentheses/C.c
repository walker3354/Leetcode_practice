#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int s_len = strlen(s);
    if (s_len % 2 != 0) return false;
    if (s_len == 0) return true;

    char* stack = malloc(s_len);
    int last_pos = 0;
    memset(stack, 0, s_len);

    for (int i = 0; i < s_len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[last_pos++] = s[i];
        } else if (s[i] == ')') {
            if (last_pos == 0 || stack[last_pos - 1] != '(') {
                last_pos = -1;
                break;
            }
            last_pos--;
        } else if (s[i] == '}') {
            if (last_pos == 0 || stack[last_pos - 1] != '{') {
                last_pos = -1;
                break;
            }
            last_pos--;
        } else if (s[i] == ']') {
            if (last_pos == 0 || stack[last_pos - 1] != '[') {
                last_pos = -1;
                break;
            }
            last_pos--;
        }
    }
    bool result = (last_pos == 0 ? true : false);
    free(stack);
    return result;
}