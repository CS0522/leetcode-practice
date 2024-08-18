/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 双指针
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4)
            return res;
        
        // nums[i] + nums[j] + nums[left] + nums[right]
        size_t nums_size = nums.size();
        for (size_t i = 0; i < nums_size; i++)
        {
            // 对 a 去重
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;
            for (size_t j = i + 1; j < nums_size; j++)
            {
                // 对 b 去重
                if (j >= i + 2 && nums[j] == nums[j - 1])
                    continue;
                
                int left = j + 1;
                int right = nums_size - 1;
                while (left < right)
                {
                    while (left < right && 
                            (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right] > target)
                        --right;
                    while (left < right &&
                            (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right] < target)
                        ++left;
                    // 如果不满足条件
                    if (left >= right)
                        break;
                    // 满足条件
                    else if ((long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right] == target)
                    {
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        // 指针前进去重
                        ++left;
                        while (left < right && nums[left] == nums[left - 1])
                            ++left;
                        --right;
                        while (left < right && nums[right] == nums[right + 1])
                            --right;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

