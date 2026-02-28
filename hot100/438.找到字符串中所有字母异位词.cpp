/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 * 解决思路：滑动窗口，通过窗口内字符出现次数来比较子串是否与模式串相同
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> res;
            
            int s_len = s.length(), p_len = p.length();
            if (s_len < p_len)
                return res;
            // 滑动窗口，滑动过程中，对每个字符出现次数进行计数
            vector<int> s_char_count(26, 0);
            vector<int> p_char_count(26, 0);
            for (size_t i = 0; i < p_len; i++)
            {
                ++p_char_count[p[i] - 'a'];
                ++s_char_count[s[i] - 'a'];
            }
    
            for (size_t i = 0; i + p_len <= s_len; i++)
            {
                if (s_char_count == p_char_count)
                    res.push_back(i);
                
                --s_char_count[s[i] - 'a'];
                if (i + p_len < s_len)
                    ++s_char_count[s[i + p_len] - 'a'];
            }
            return res;
        }
    };
// @lc code=end

