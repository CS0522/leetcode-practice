/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeros_idx;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == 0)
                    zeros_idx.push_back({i, j});
        for (const auto& idx : zeros_idx)
        {
            int zero_col = idx.second;
            for (int i = 0; i < row; i++)
                matrix[i][zero_col] = 0;
            int zero_row = idx.first;
            for (int j = 0; j < col; j++)
                matrix[zero_row][j] = 0;
        }
    }
};
// @lc code=end

