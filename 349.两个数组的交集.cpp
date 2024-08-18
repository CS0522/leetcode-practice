/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 哈希集合
        unordered_set<int> us;
        // 为了去除重复
        // 结果集合
        unordered_set<int> us_no_repeat;
        // 遍历数组1，加入到哈希集合
        for (int i = 0; i < nums1.size(); i++)
        {
            us.insert(nums1[i]);
        }
        // 遍历数组2，查找相同元素
        for (int i = 0; i < nums2.size(); i++)
        {
            if (us.count(nums2[i]) && !us_no_repeat.count(nums2[i]))
            {
                us_no_repeat.insert(nums2[i]);
            }
        }

        return vector<int>(us_no_repeat.begin(), us_no_repeat.end());
    }
};
// @lc code=end

