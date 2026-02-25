/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 * 解决思路：双指针
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
    public:
        // 双指针
        int maxArea(vector<int>& height) {
            int left = 0, right = height.size() - 1;
            int max_area = 0, curr_area = 0;
            int limit_height = 0;
            while (left < right)
            {
                limit_height = min(height[left], height[right]);
                curr_area = (right - left) * limit_height;
                max_area = max(curr_area, max_area);
    
                if (height[left] < height[right])
                    left++;
                else
                    right--;
            }
            return max_area;
        }
    };
// @lc code=end

