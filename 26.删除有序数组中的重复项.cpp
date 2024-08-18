/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 快慢指针
        int slow = 1;
        // 存储上一个比较元素
        int temp = nums[0];
        for (int fast = 1; fast < nums.size();fast++)
        {
            // 非重复元素
            if (nums[fast] != temp)
            {
                nums[slow++] = nums[fast];
                temp = nums[fast];
            }
            // 重复元素
            // fast 指针前进
        }
        return slow;
    }
};
// @lc code=end

