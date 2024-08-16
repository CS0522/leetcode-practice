/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 用类似 map 的数据结构
        // 保存对应关系
        map<char, char> brace_mp;
        brace_mp.insert(make_pair<>('(', ')'));
        brace_mp.insert(make_pair<>('[', ']'));
        brace_mp.insert(make_pair<>('{', '}'));

        stack<char> left_brace_st;
        for (int i = 0; i < s.length(); i++)
        {
            // 左括号入栈
            // 右括号弹出栈
            if (brace_mp.count(s[i]))   // 左括号
                left_brace_st.push(s[i]);
            
            else                        // 右括号
            {
                if (!left_brace_st.empty())
                {
                    auto tmp_left_brace = left_brace_st.top();

                    if (s[i] != brace_mp[tmp_left_brace])
                        break;          // 跳出循环，残留元素，统一 return false
                    else
                        left_brace_st.pop();
                }
                else
                    return false;
            }
        }

        return left_brace_st.empty();
    }
};
// @lc code=end

