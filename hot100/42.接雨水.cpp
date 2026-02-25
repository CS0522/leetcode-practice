/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 * 解决思路：双指针；接水量 = min(左最高，右最高) - 当前高度
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
    public:
        int trap(vector<int>& height) {
            int left = 0, right = height.size() - 1;
            int left_max = 0, right_max = 0;
            int total_sum = 0;
            while (left < right)
            {
                left_max = max(left_max, height[left]);
                right_max = max(right_max, height[right]);
                if (height[left] < height[right])
                {
                    total_sum += left_max - height[left];
                    left++;
                    
                }
                else
                {
                    total_sum += right_max - height[right];
                    right--;
                    
                }
            }
            return total_sum;
        }
    };
// @lc code=end

