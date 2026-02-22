class Solution {
    public:
        int hammingWeight(int n) {
            int bit_counter = 0;
            for (int i = 0; i < (sizeof(int) * 8); i++) {
                if ((n & (1U << i)) != 0) bit_counter++;
            }
            return bit_counter;
        }

        int better_loop_version(int n) {
            int bit_counter = 0;
            while (n != 0) {
                n = n & (n - 1);
                bit_counter++;
            }
            return bit_counter;
        }
};