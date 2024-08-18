/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())
            return false;
        vector<int> counts(26, 0);
        for (int i = 0; i < magazine.length(); ++i)
        {
            ++counts[magazine[i] - 'a'];
        }
        for (int i = 0; i < ransomNote.length(); ++i)
        {
            --counts[ransomNote[i] - 'a'];
            // 如果 < 0，说明 magazine 中的字母数不够
            if (counts[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

