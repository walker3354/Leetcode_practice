#include <stack>
using namespace std;

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
    private:
        stack<int> in_stack;
        stack<int> out_stack;

    public:
        MyQueue() {}

        void push(int x) { in_stack.push(x); }

        int pop() {
            if (out_stack.empty()) {
                while (!in_stack.empty()) {
                    out_stack.push(in_stack.top());
                    in_stack.pop();
                }
            }
            int result = out_stack.top();
            out_stack.pop();
            return result;
        }

        int peek() {
            if (out_stack.empty()) {
                while (!in_stack.empty()) {
                    out_stack.push(in_stack.top());
                    in_stack.pop();
                }
            }
            int result = out_stack.top();
            return result;
        }

        bool empty() {
            if (in_stack.empty() && out_stack.empty()) return true;
            return false;
        }
};
