#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_node {
        char val;
        struct stack_node* prev;
} stack_node;

void clean_stack(stack_node* last_char) {
    while (last_char != NULL) {
        stack_node* temp = last_char;
        last_char = last_char->prev;
        free(temp);
    }
}

bool isValid(char* s) {
    int s_len = strlen(s);
    if (s_len < 2 || s_len % 2 != 0) return false;

    stack_node* last_char = malloc(sizeof(stack_node));
    stack_node* stack_begin = last_char;
    last_char->prev = NULL;

    for (int i = 0; i < s_len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack_node* temp_node = malloc(sizeof(stack_node));
            temp_node->prev = last_char;
            temp_node->val = s[i];
            last_char = temp_node;
        } else if (s[i] == '}') {
            if (last_char == stack_begin || last_char->val != '{') {
                clean_stack(last_char);
                return false;
            }
            stack_node* temp = last_char;
            last_char = last_char->prev;
            free(temp);
        } else if (s[i] == ']') {
            if (last_char == stack_begin || last_char->val != '[') {
                clean_stack(last_char);
                return false;
            }
            stack_node* temp = last_char;
            last_char = last_char->prev;
            free(temp);
        } else if (s[i] == ')') {
            if (last_char == stack_begin || last_char->val != '(') {
                clean_stack(last_char);
                return false;
            }
            stack_node* temp = last_char;
            last_char = last_char->prev;
            free(temp);
        }
    }

    bool clear_flag = (stack_begin == last_char ? true : false);
    clean_stack(last_char);
    return clear_flag;
}