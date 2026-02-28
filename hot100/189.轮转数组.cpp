/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 * 解决思路：数组翻转
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int p = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + p);
        reverse(nums.begin() + p, nums.end());
    }
};

// @lc code=end

