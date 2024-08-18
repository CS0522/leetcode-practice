/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 用栈
        stack<string> st;
        string tmp = "";
        for (int i = 0; i < s.length(); i++)
        {
            // 遇到空格压入栈
            if (s[i] == ' ')
            {
                if (tmp != "")
                    st.push(tmp);
                tmp = "";
            }
            // 非空格更新临时字符串
            else
                tmp += s[i];
        }
        // 最后一个单词压入栈
        if (tmp != "")
            st.push(tmp);

        // 输出
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
            // 为了最后一个单词尾部没有空格
            if (!st.empty())
                res += " ";
        }
        
        return res;
    }
};
// @lc code=end

