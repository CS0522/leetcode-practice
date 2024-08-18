/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // move window
        int n = nums.size();
        int minLen = n;
        int start = 0;
        int end = 0;
        int sum = 0;
        bool found = false;
        while (end < n && start <= end)
        {
            sum += nums[end];
            // 不满足条件，end前进
            if (sum < target)
            {
                end++;
            }
            // 满足条件，start前进，为了找到最小长度
            else
            {
                found = true;
                // 若更小，update minLen
                if ((end - start + 1) < minLen)
                    minLen = end - start + 1;
                sum -= nums[start] + nums[end];
                start++;
            }
        }

        return (found ? minLen : 0);
    }
};
// @lc code=end

