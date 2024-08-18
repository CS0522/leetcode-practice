/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// 快慢指针
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 快慢指针
        int s_slow = 0;
        for (int fast = 0; fast < s.size(); ++fast)
        {
            // not '#'
            if (s[fast] != '#')
                s[s_slow++] = s[fast];
            // is '#'
            else
            {
                if (s_slow > 0)
                {
                    s_slow--;
                }
            }
        }
        // 新 s 长度为 s_slow

        int t_slow = 0;
        for (int fast = 0; fast < t.size(); ++fast)
        {
            // not '#'
            if (t[fast] != '#')
                t[t_slow++] = t[fast];
            // is '#'
            else
            {
                if (t_slow > 0)
                {
                    t_slow--;
                }
            }
        }
        // 新 t 长度为 t_slow

        // length is not equal
        if (s_slow != t_slow)
            return false;
        // length is equal
        else
        {
            for (int i = 0; i < s_slow; i++)
            {
                // 存在一个不一样
                if (s[i] != t[i])
                    return false;
            }
            return true;
        }
    }
};
// @lc code=end

