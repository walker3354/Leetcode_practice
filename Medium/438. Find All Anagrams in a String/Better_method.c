#include <stdlib.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    *returnSize = 0;

    if (s_len < p_len) return NULL;

    int* result = malloc((s_len - p_len + 1) * sizeof(int));
    int target_map[26] = {0};
    int record_map[26] = {0};

    int unique = 0;
    for (int i = 0; i < p_len; i++) {
        if (target_map[p[i] - 'a'] == 0) unique++;
        target_map[p[i] - 'a']++;
    }

    int match = 0;
    for (int right = 0; right < s_len; right++) {
        int c = s[right] - 'a';
        record_map[c]++;
        if (record_map[c] == target_map[c])
            match++;
        else if (record_map[c] == target_map[c] + 1)
            match--;

        if (right >= p_len) {
            int l = s[right - p_len] - 'a';
            if (record_map[l] == target_map[l]) match--;
            record_map[l]--;
            if (record_map[l] == target_map[l]) match++;
        }

        if (match == unique) { // ✅ 用 unique 而不是 26
            result[(*returnSize)++] = right - p_len + 1;
        }
    }

    return result;
}