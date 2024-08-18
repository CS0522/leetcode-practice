/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int str_len = s.size();
        char tmp;
        for (int i = 0; i < str_len / 2; i++)
        {
            tmp = s[i];
            s[i] = s[str_len - 1 -i];
            s[str_len - 1 -i] = tmp;
        }
    }
};
// @lc code=end

