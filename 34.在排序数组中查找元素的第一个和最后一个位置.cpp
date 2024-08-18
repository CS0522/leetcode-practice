/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // empty
        if (nums.size() == 0)
        {
            return vector<int> {-1, -1};
        }

        vector<int> res(2);
        int left = 0;
        int right = nums.size() - 1;
        // 提前赋值
        int first = -1;
        int last = -1;

        // 分两次查找
        // 查找第一个
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                // 往左边找，找到第一个位置
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // 查找第二个
        left = 0;
        right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                // 往右边找，找到最后一个位置
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        res[0] = first;
        res[1] = last;
        return res;
    }
};
// @lc code=end

