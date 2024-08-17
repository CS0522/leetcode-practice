/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> ele_freq;

        // 用 map 键值对先存储每个元素对应的出现次数
        for (int i = 0; i < nums.size(); i++)
            ele_freq[nums[i]]++;

        // map 不能根据 value 排序
        // 使用 vector 接收 map 数据，并排序
        vector<pair<int, int>> map_eles;
        for(auto it = ele_freq.begin(); it != ele_freq.end(); it++)
        {
            map_eles.emplace_back(pair<int, int>(it->first, it->second));
        }
        
        auto cmp = [] (pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; };
        // 应该不需要 sort，只需要前 k 个即可
        // 可以使用 k-小顶堆：当大于 top 元素，弹出堆顶后入堆
        // 最后堆中元素为最大的 k 个
        sort(map_eles.begin(), map_eles.end(), cmp);

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(map_eles[i].first);
        }

        return res;
    }
};
// @lc code=end

