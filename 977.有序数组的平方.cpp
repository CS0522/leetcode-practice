/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // **非递减顺序**
        int len = nums.size();
        vector<int> res(len);

        // 左右指针
        int left = 0;
        int right = len - 1;
        int pos = len - 1;
        // left <= right，这样才是写入了 5 次数据
        // 如果是 left < right，
        // 这时候循环内最后加入的数只能是 left 或者 right
        // 有一个还没有被处理
        for (; left <= right; )
        {
            int left_square = nums[left] * nums[left];
            int right_square = nums[right] * nums[right];
            if (left_square > right_square)
            {
                res[pos] = left_square;
                left++;
            }
            else
            {
                res[pos] = right_square;
                right--;
            }
            pos--;
        }

        return res;
    }
};
// @lc code=end

