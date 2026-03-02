#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> stack_str;
            stringstream ss(path);
            string token;
            while (getline(ss, token, '/')) {
                if (token == "" || token == ".") continue;
                if (token == "..") {
                    if (!stack_str.empty()) stack_str.pop_back();
                } else {
                    stack_str.push_back(token);
                }
            }

            string result = "";
            for (auto& toekn : stack_str) {
                result += ("/" + toekn);
            }
            return (result.empty() ? "/" : result);
        }
};