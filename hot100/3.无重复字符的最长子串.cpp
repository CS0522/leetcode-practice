/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * 解决思路：指针滑动窗口
 */
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> chars;
            int left = 0, right = 0;
            int max_length = 0;
            while (left < s.size())
            {
                if (left != 0)
                    chars.erase(s[left - 1]);
                
                while (right < s.size() &&
                        !chars.count(s[right]))
                {
                    chars.insert(s[right]);
                    right++;
                }
    
                max_length = max(max_length, right - left);
                left++;
            }
            return max_length;
        }
    };
// @lc code=end

