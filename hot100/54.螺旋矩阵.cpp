/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();
        int num = row * col;
        vector<pair<int, int>> direction = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        int round = direction.size();
        int visited_num = 0;
        int p = 0, q = 0;
        int curr = 0;
        while (visited_num != num)
        {
            if (!visited[p][q])
            {
                res.push_back(matrix[p][q]);
                visited[p][q] = 1;
                visited_num++;
            }
            // 前进
            int next_p = p + direction[curr % round].first;
            int next_q = q + direction[curr % round].second;
            if (next_p >= row || next_q >= col 
                || next_p < 0 || next_q < 0
                || visited[next_p][next_q])
            {
                // 转向
                curr++;
                next_p = p + direction[curr % round].first;
                next_q = q + direction[curr % round].second;
            }
            p = next_p;
            q = next_q;
        }
        return res;
    }
};
// @lc code=end

