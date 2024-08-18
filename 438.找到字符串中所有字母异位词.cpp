/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        if (s_len < p_len)
            return {};
        // 滑动窗口 + 哈希表
        vector<int> s_counts(26, 0);
        vector<int> p_counts(26, 0);
        // 存储 indices
        vector<int> ans;
        // 初始化
        for (int i = 0; i < p_len; ++i)
        {
            ++s_counts[s[i] - 'a'];
            ++p_counts[p[i] - 'a'];
        }
        // 滑动窗口遍历 s
        for (int i = 0; i < s_len - p_len; ++i)
        {
            // 如果哈希数组相同
            if (s_counts == p_counts)
                ans.emplace_back(i);
            // 不相同，滑动窗口前进，前面的自减，后面的自加
            --s_counts[s[i] - 'a'];
            ++s_counts[s[i + p_len] - 'a'];
        }

        // 最后再比较一次，如果哈希数组相同
        if (s_counts == p_counts)
            ans.emplace_back(s_len - p_len);

        return ans;
    }
};
// @lc code=end

