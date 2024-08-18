/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class MyQueue {
private:
    stack<int> st;
    stack<int> tmp_st;
    
public:
    MyQueue() {
    }
    
    void push(int x) {
        this->st.push(x);
    }
    
    int pop() {
        while (!st.empty())
        {
            tmp_st.push(st.top());
            st.pop();
        }
        auto res = tmp_st.top();
        tmp_st.pop();
        // 元素还回 st
        while (!tmp_st.empty())
        {
            st.push(tmp_st.top());
            tmp_st.pop();
        }

        return res;
    }
    
    int peek() {
        while (!st.empty())
        {
            tmp_st.push(st.top());
            st.pop();
        }
        auto res = tmp_st.top();
        // tmp_st.pop();
        // 元素还回 st
        while (!tmp_st.empty())
        {
            st.push(tmp_st.top());
            tmp_st.pop();
        }

        return res;
    } 
    
    bool empty() {
        return (st.empty() && tmp_st.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

