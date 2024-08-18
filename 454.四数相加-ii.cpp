/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // nums1 + nums2 = - nums3 - nums4
        unordered_map<int, int> um;
        int res = 0;
        int nums_size = nums1.size();
        // 先遍历 nums1，nums2，保存所有可能取值
        for (int i = 0; i < nums_size; ++i)
        {
            for (int j = 0; j < nums_size; ++j)
            {
                ++um[nums1[i] + nums2[j]];
            }
        }
        // 后遍历 nums3，nums4，查找哈希集合中是否有其相反数
        for (int i = 0; i < nums_size; ++i)
        {
            for (int j = 0; j < nums_size; ++j)
            {
                int opp_count = um[0 - nums3[i] - nums4[j]];
                // 如果找到了，并且有可能不止一个
                if (opp_count)
                    res += opp_count;
            }
        }

        return res;
    }
};
// @lc code=end

