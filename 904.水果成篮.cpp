/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        // 对应种类和出现次数
        unordered_map<int, int> count;

        int start = 0;
        int maxLen = 0;
        for (int end = 0; end < n; ++end)
        {
            // 加入当前键值
            ++count[fruits[end]];
            // 当种类超过2
            while (count.size() > 2)
            {
                // 迭代器取得fruits中最左边的数
                // 删除这个元素，start指针对应前进
                auto it = count.find(fruits[start]);
                --it->second;
                if (it->second == 0)
                {
                    count.erase(it);
                }
                ++start;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};
// @lc code=end

