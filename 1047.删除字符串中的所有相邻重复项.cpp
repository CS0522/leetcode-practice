/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // 用栈
        stack<char> uniques;
        for (int i = 0; i < s.length(); i++)
        {
            if ((!uniques.empty() && s[i] != uniques.top()) || uniques.empty())
            {
                uniques.push(s[i]);
            }
            else if (!uniques.empty() && s[i] == uniques.top())
            {
                uniques.pop();
            }
        }
        // stack 中即为最后的结果
        string res = "";
        while (!uniques.empty())
        {
            res += uniques.top();
            uniques.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

