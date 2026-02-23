/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 哈希表 map，key 为排序后的 str，值为对应的 vector<string>
        unordered_map<string, vector<string>> um;
        for (string str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            um[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            res.emplace_back(it->second);
        }
        return res;
    }
};
// @lc code=end

