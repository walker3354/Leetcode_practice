#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            // assume the first must be "/"
            vector<string> stack_str;
            stack_str.push_back(string(1, path[0]));
            for (int i = 1; i < path.size(); i++) {
                string& back_str = stack_str.back();
                string c(1, path[i]);
                if (back_str == "/" && c == "/") {
                    if (i == (path.size() - 1)) continue;
                    continue;
                } else if (back_str == ".." && c == "/") {
                    remove_foler_path(stack_str);
                } else if (back_str == "." && c == "/") {
                    stack_str.pop_back(); // remove "."
                    if (i == (path.size() - 1)) stack_str.pop_back();
                } else if (back_str == "/") {
                    if (i == (path.size() - 1)) continue;
                    stack_str.push_back(c);
                } else if ((c == "/")) {
                    if (i == (path.size() - 1)) continue;
                    stack_str.push_back(c);
                } else {
                    back_str += c;
                }
            }

            string result;
            for (auto& str : stack_str) result += str;
            return result;
        }

        void remove_foler_path(vector<string>& stack_str) { // this assume legal
            stack_str.pop_back();                           // ".."
            stack_str.pop_back();                           // "/"
            if (stack_str.empty()) {
                stack_str.push_back("/");
            }
            stack_str.pop_back(); // folder name
        }
};