/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 * 解决思路：索引左侧乘积 * 索引右侧乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> res(nums_size, 1);
        // 计算索引左侧乘积
        for (int i = 1; i < nums_size; i++)
            res[i] = nums[i - 1] * res[i - 1];
        // 计算索引右边乘积
        int right_times = 1;
        for (int j = nums_size - 1; j >= 0; j--)
        {
            res[j] = res[j] * right_times;
            right_times *= nums[j];
        }
        return res;
    }
};
// @lc code=end

