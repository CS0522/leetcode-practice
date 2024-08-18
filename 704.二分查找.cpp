/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        // left bound
        if (nums[left] == target)
        {
            return left;
        }
        // right bound
        if (nums[right] == target)
        {
            return right;
        }
        // binary search
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }
        // not found
        return -1;
    }
};
// @lc code=end

