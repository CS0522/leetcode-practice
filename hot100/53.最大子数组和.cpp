/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 * 解决思路：动态规划，反向遍历，记录以当前元素为起始的连续序列的最大和
 */

// @lc code=start
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            const int nums_size = nums.size();
            int max_sum = nums[nums_size - 1];
            // 记录以 i 开始的连续子数组最大和
            int *max_sums = new int[nums_size];
            max_sums[nums_size - 1] = nums[nums_size - 1];
            for (int i = nums_size - 2; i >= 0; i--)
            {
                max_sums[i] = max(max_sums[i + 1] + nums[i], nums[i]);
                if (max_sum < max_sums[i])
                    max_sum = max_sums[i];
            }
            return max_sum;
        }
    };
// @lc code=end

