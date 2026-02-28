/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 * 解决思路：bitmap 方式模拟数轴，考虑特殊区间情况如 [0, 0]
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        bool bitmap[10001] = {0};
        vector<vector<int>> res;
        // 特殊区间，考虑如 [0, 0] 这种情况
        unordered_set<int> specials;
        // bitmap 每一格表示：n-1 ~ n 这个区间
        for (const auto& interval : intervals)
        {
            if (interval[0] == interval[1])
            {
                specials.insert(interval[0]);
                continue;
            }
            for (int i = interval[0]; i < interval[1]; i++)
                bitmap[i] = 1;
        }
        // 遍历 bitmap
        vector<int> interval_wo_overlap;
        for (int i = 0; i < 10001; i++)
        {
            if (bitmap[i])
            {
                if (i == 0 ||
                     ((i != 0) && !bitmap[i - 1]))
                    interval_wo_overlap.push_back(i);
            }
            else
            {
                if (i != 0 && bitmap[i - 1])
                {
                    interval_wo_overlap.push_back(i);
                    res.push_back(interval_wo_overlap);
                    interval_wo_overlap.clear();
                }
            }
        }
        for (const int& s : specials)
        {
            if (bitmap[s] || (s != 0 && bitmap[s - 1]))
                continue;
            else
                res.push_back({s, s});
        }
        return res;
    }
};
// @lc code=end

