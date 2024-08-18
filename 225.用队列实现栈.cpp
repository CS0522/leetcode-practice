/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class MyStack {
private:
    queue<int> inQ;

public:
    MyStack() {
    }
    
    void push(int x) {
        inQ.push(x);
    }
    
    int pop() {
        auto inQ_size = inQ.size();
        // 返回最后一个元素
        int ele_cnt = 0;
        while (ele_cnt != inQ_size - 1)
        {
            inQ.push(inQ.front());
            inQ.pop();

            ele_cnt += 1;
        }
        // 此时队头元素为要 pop 的元素
        auto res = inQ.front();
        inQ.pop();

        return res;
    }
    
    int top() {
        auto inQ_size = inQ.size();
        // 返回最后一个元素
        int ele_cnt = 0;
        while (ele_cnt != inQ_size - 1)
        {
            inQ.push(inQ.front());
            inQ.pop();

            ele_cnt += 1;
        }
        // 此时队头元素为要 pop 的元素
        auto res = inQ.front();
        
        inQ.push(inQ.front());
        inQ.pop();

        return res;
    }
    
    bool empty() {
        return inQ.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

