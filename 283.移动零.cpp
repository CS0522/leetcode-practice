/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        // 快慢指针
        int slow = 0;
        int fast = 0;
        while (fast < len)
        {
            // 右边不是 0，交换
            if (nums[fast] != 0)
            {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
    }
};
// @lc code=end

