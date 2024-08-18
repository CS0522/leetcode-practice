/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 计算 next 数组
    void calNext(int *next, string &pattern)
    {
        // 回溯指针
        // 也可以表示最长前缀长度
        int j = -1;
        // 默认 next[0] = -1
        next[0] = -1;
        for (int i = 1; i < pattern.length(); i++)
        {
            // 当正在匹配的字符 p[i] 
            // 与正在匹配的最长前缀的下一位 p[j + 1] 
            // 匹配失败时，
            // j 回溯到最长前缀的上一个最长前缀
            while (j != -1 && pattern[i] != pattern[j + 1])
            {
                j = next[j];
            }
            // 匹配成功
            // 最长前缀 + 1
            if (pattern[i] == pattern[j + 1])
            {
                j += 1;
            }
            next[i] = j;
        }
    }

    // KMP
    bool KMP(string &text, string &pattern, int *next)
    {
        // int next[pattern.length()];
        // // 计算 next 数组
        // calNext(next, pattern);
        int j = -1;
        // 开始匹配
        for (int i = 0; i < text.length(); i++)
        {
            while (j != -1 && text[i] != pattern[j + 1])
            {
                j = next[j];
            }
            if (text[i] == pattern[j + 1])
            {
                j++;
            }
            // 当 j 匹配到模式串最后一位
            // 匹配成功
            if (j == pattern.length() - 1)
            {
                return true;
            }
        }
        // 匹配失败
        return false;
    }


    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        bool flag = false;
        // i 为长度
        for (int i = len / 2; i >= 1; i--)
        {
            // NOTE: 剪枝处理
            // 只有倍数才满足要求
            // 可以节省很多循环
            if (len % i != 0)
                continue;
            string pattern = s.substr(0, i);
            // pattern 作为模式串
            // 用 KMP 算法进行匹配
            int next[pattern.length()];
            calNext(next, pattern);
            // end 为已经匹配成功的下标 + 1
            int end = i;
            while (end != len)
            {
                string text = s.substr(end, i);
                // 部分匹配失败
                // 退出 while，for 循环 continue
                if (!KMP(text, pattern, next))
                    break;
                // 部分匹配成功
                else
                    end += i;
            }
            // 匹配成功
            if (end == len)
                return true;
            // 该字串匹配失败
            else
                continue;
        }
        // 全部匹配失败
        return false;
    }
};
// @lc code=end

