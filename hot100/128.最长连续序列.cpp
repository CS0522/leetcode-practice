/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 * 思路:
 * 暴力做法就是对当前的 x，逐步 +1，判断 x + N 是否在集合内
 * 优化点在很多遍历是重复的
 * 当当前的 x，他的前序不在集合内时，那么 x 可能作为连续序列的头
 * 否则，x 应该是连续序列的中间，直接跳过
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 去重
        unordered_set<int> unique_set;
        for (auto num : nums)
            unique_set.insert(num);

        int max_length = 0, current_length = 1;
        for (auto num : unique_set)
        {
            if (!unique_set.count(num - 1))
            {
                current_length = 1;

                while (unique_set.count(++num))
                    current_length++;
                
                max_length = max(max_length, current_length);
            }
        }

        return max_length;
    }
};
// @lc code=end

