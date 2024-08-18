/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        // directions
        // 顺时针方向
        // 一维为某个方向，二维为 row 和 col
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // 最大的数
        int max_num = n * n;
        // results
        vector<vector<int>> spiral_metrix(n, vector<int>(n, 0));
        // 当前的数
        int curr_num = 1;
        int row = 0, col = 0;
        // 当前的方向
        int curr_direct = 0;
        // 按数填充
        while (curr_num <= max_num)
        {
            spiral_metrix[row][col] = curr_num;
            ++curr_num;
            // 计算下一个要填充的数的 row 和 col
            int next_row = row + directions[curr_direct][0];
            int next_col = col + directions[curr_direct][1];
            // 当超出范围或者碰到已经访问过的，则改变方向
            if (next_row >= n || next_col >= n || 
                next_row < 0 || next_col < 0 ||
                spiral_metrix[next_row][next_col] != 0)
            {
                // change direction
                curr_direct = (curr_direct + 1) % 4;
            }
            // 重新计算
            next_row = row + directions[curr_direct][0];
            next_col = col + directions[curr_direct][1];  

            row = next_row;
            col = next_col;
        } 

        return spiral_metrix;
    }
};
// @lc code=end

