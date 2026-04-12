#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2); // did s1 contain in s2?
    if (s2_len < s1_len) return false;

    int record_map[26] = {0};
    int target_map[26] = {0};
    int unique_counter = 0;
    int finish_counter = 0;
    for (int i = 0; i < s1_len; i++) {
        int temp = s1[i] - 'a';
        if (target_map[temp] == 0) unique_counter++;
        target_map[temp] += 1;
    }

    for (int i = 0; i < s2_len; i++) {
        int temp = s2[i] - 'a';
        record_map[temp] += 1;
        if (record_map[temp] == target_map[temp]) {
            finish_counter += 1;
            // if (finish_flag == unique_counter) return true;
        } else if (record_map[temp] == target_map[temp] + 1) {
            finish_counter -= 1;
        }

        if (i >= s1_len) {
            int l = s2[i - s1_len] - 'a';
            if (record_map[l] == target_map[l]) finish_counter--;
            record_map[l] -= 1;
            if (record_map[l] == target_map[l]) finish_counter++;
        }
        if (finish_counter == unique_counter) return true;
    }
    return false;
}