#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size() - 2; i++) {
                if (nums[i] > 0) break;
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == 0) {
                        result.push_back({nums[i], nums[left], nums[right]});
                        while (left < right && nums[++left] == nums[left - 1]) {
                        }
                        while (left < right &&
                               nums[--right] == nums[right + 1]) {
                        }
                    } else if (sum < 0) {
                        while (left < right && nums[++left] == nums[left - 1]) {
                        }
                    } else {
                        while (left < right &&
                               nums[--right] == nums[right + 1]) {
                        }
                    }
                }
            }

            return result;
        }
};