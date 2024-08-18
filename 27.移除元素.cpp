/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // val 是要删除的元素
        // 快慢指针
        // slow 用于写入
        // fast 用于查找
        int slow = 0;
        int fast = 0;
        for (; fast < nums.size(); fast++)
        {
            // 当 val != fast，慢指针写入快指针数值
            // 快慢指针同时前进
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
            // 当 al == fast，慢指针不写入
            // 慢指针不动，快指针前进
        }
        return slow;
    }
};
// @lc code=end

