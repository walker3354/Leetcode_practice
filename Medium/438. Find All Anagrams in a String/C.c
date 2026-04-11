#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool check_amagrams(char* s, int s_len, char* p, int p_len, int check_pos,
                    int* target_map) {
    if (check_pos + p_len > s_len) return false;
    int* record_map = calloc(128, sizeof(int)); // 128 = ASCII

    for (int i = check_pos; i < check_pos + p_len; i++) {
        record_map[(int)s[i]] += 1;
    }
    for (int i = 0; i < 128; i++) {
        if (record_map[i] != target_map[i]) {
            free(record_map);
            return false;
        }
    }
    free(record_map);
    return true;
}

int* findAnagrams(char* s, char* p, int* returnSize) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    if (s_len < p_len) {
        *returnSize = 0;
        return NULL;
    }
    int* temp = malloc((s_len - p_len + 1) * sizeof(int));
    int temp_counter = 0;
    memset(temp, -1, (s_len - p_len + 1));

    int* target_map = calloc(128, sizeof(int));
    for (int i = 0; i < p_len; i++) {
        target_map[(int)p[i]] += 1;
    }

    for (int i = 0; i < s_len; i++) {
        if (check_amagrams(s, s_len, p, p_len, i, target_map) == true) {
            temp[temp_counter] = i;
            temp_counter++;
        }
    }

    int* final_result = malloc(temp_counter * sizeof(int));
    *returnSize = temp_counter;
    for (int i = 0; i < temp_counter; i++) {
        final_result[i] = temp[i];
    }
    free(temp);
    free(target_map);
    return final_result;
}