#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stack_in, stack_out;

    MyQueue() {
    }
    
    void push(int x) {
        stack_in.push(x);
    }
    
    int pop() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int front = stack_out.top();
        stack_out.pop();
        return front;
    }
    
    int peek() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }
    
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
};
