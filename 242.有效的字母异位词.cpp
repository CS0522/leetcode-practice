/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }
        // 建立哈希表，保存每个字符出现的次数
        int char_count[26] = {0};
        for (int i = 0; i < s.length(); ++i)
        {
            char_count[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.length(); ++i)
        {
            char_count[t[i] - 'a'] -= 1;
        }
        // 如果刚好所有 char_count 里的值均为 0
        // 则 s，t 为异位词
        for (int i = 0; i < 26; ++i)
        {
            if (char_count[i])
            {
                return false;
            }
        }
        return true;
    }   
};
// @lc code=end

