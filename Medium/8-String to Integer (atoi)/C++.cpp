#include <climits> // 提供 INT_MAX 和 INT_MIN
#include <string>

using namespace std;
class Solution {
    public:
        int myAtoi(string s) {
            int index = 0;
            int result = 0;
            int sign = 1;
            while (s[index] == ' ' && index < s.size()) {
                index++;
            }
            if (index >= s.size()) return 0;

            if (s[index] == '+' || s[index] == '-') {
                sign = (s[index] == '-') ? -1 : 1;
                index++;
            }

            while (s[index] >= '0' && s[index] <= '9' && index < s.size()) {
                int number = s[index] - '0';
                if (result > (INT_MAX - number) / 10)
                    return (sign == 1 ? INT_MAX : INT_MIN);
                result = result * 10 + number;
                index++;
            }

            return sign * result;
        }
};
