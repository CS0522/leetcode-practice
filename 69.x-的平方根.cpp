/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = -1;
        while (low <= high)
        {
            long mid = (low + high) / 2;
            long mid_square = mid * mid;
            if (mid_square <= x)
            {   
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

