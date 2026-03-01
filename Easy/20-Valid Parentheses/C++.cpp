#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        //{} [] ()
        bool isValid(string s) {
            if (s.size() < 2) return false;
            stack<char> temp_stack;
            for (auto& c : s) {
                if (c == '{') {
                    temp_stack.push('}');
                } else if (c == '[') {
                    temp_stack.push(']');
                } else if (c == '(') {
                    temp_stack.push(')');
                } else {
                    if (temp_stack.empty() || temp_stack.top() != c)
                        return false;
                    temp_stack.pop();
                }
            }
            return temp_stack.empty();
        }

        bool bad_method(string s) {
            if (s.size() == 1) return false;

            vector<char> string_temp;
            for (int i = 0; i < s.size(); i++) {
                char temp_char = s[i];
                if (temp_char == '(' || temp_char == '[' || temp_char == '{') {
                    string_temp.push_back(temp_char);
                } else if (temp_char == ')' || temp_char == ']' ||
                           temp_char == '}') {
                    if (string_temp.empty()) return false;
                    if (temp_char == ')' && string_temp.back() == '(') {
                        string_temp.pop_back();
                        continue;
                    }
                    if (temp_char == ']' && string_temp.back() == '[') {
                        string_temp.pop_back();
                        continue;
                    }
                    if (temp_char == '}' && string_temp.back() == '{') {
                        string_temp.pop_back();
                        continue;
                    }
                    return false;
                } else {
                    return false;
                }
            }
            if (string_temp.empty()) return true;
            return false;
        }
};