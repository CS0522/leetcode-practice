/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 * 解决思路：左右指针，并使用哈希表做计数器
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<char, int> sub_count, pattern_count;
    bool canCover() 
    {
        for (const auto &p: pattern_count) {
            if (sub_count[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        string min_str;
        int t_len = t.length(), s_len = s.length();
        int left = 0, right = left + t_len - 1;
        int min_len = INT_MAX;
        int min_left = left;
        int curr_len = 0;
        for (int i = 0; i < t_len; i++)
            pattern_count[t[i]]++;
        // 将前 t_len 个填充进计数器
        for (int i = 0; i < t_len; i++)
            sub_count[s[i]]++;
        while (right < s_len)
        {
            curr_len = right - left + 1;
            if (canCover())
            {
                if (curr_len < min_len)
                {
                    min_len = curr_len;
                    min_left = left;
                }
                sub_count[s[left]]--;
                left++;
            }
            else
            {
                right++;
                sub_count[s[right]]++;
            }
        }
        min_str = (min_len == INT_MAX) ? "" : s.substr(min_left, min_len);
        return min_str;
    }
};
// @lc code=end

