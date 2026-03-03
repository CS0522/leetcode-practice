/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 * 解决思路：Z 型查找，沿←↓方向查找
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (target == matrix[i][j])
                return true;
            else if (target < matrix[i][j])
                j--;
            else
                i++;
        }

        return false;
    }
};
// @lc code=end

