#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    private:
        unordered_map<int, int> num_counter; // num:times

    public:
        int singleNumber(vector<int>& nums) {
            int result = 0;
            for (auto& i : nums) {
                result ^= i;
            }
            return result;
        }

        int hash_method(vector<int>& nums) { // extra
            for (auto& i : nums) {
                if (num_counter.count(i) == 0) {
                    num_counter[i] = 1;
                } else {
                    num_counter[i] += 1;
                }
            }

            for (auto& i : num_counter) {
                if (i.second == 1) return i.first;
            }
            return -1;
        }
};