#include <stdlib.h>
#include <string.h>

void reverse_string(char* s, int begin, int end) { // including space and \0
    end--;
    while (begin < end) {
        char temp_char = s[end];
        s[end] = s[begin];
        s[begin] = temp_char;
        begin++;
        end--;
    }
}

char* reverseWords(char* s) {
    int s_len = strlen(s);
    int i = 0, j = 0;
    while (i < s_len) {
        while (i < s_len && s[i] == ' ') i++;
        if (i < s_len && j > 0) s[j++] = ' ';
        while (i < s_len && s[i] != ' ') {
            s[j++] = s[i++];
        }
    }
    s[j] = '\0';
    reverse_string(s, 0, j);

    int begin = 0;
    for (int i = 0; i <= j; i++) {
        if (s[i] == ' ' || i == j) {
            reverse_string(s, begin, i);
            begin = i + 1;
        }
    }
    return s;
}