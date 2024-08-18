/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long cal_sum(int &n)
    {
        // 从个位开始保存
        long long sum = 0LL;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        // 哈希表，如果存在相同值，说明存在循环，返回 false
        unordered_set<int> us;

        auto sum = cal_sum(n);
        while (sum != 1)
        {
            // 存在循环
            if (us.count(sum))
                return false;
            // 暂时没有循环
            us.insert(sum);
            n = sum;
            sum = cal_sum(n);
        }
        // 退出 while，说明满足 sum == 1
        return true;
    }
};
// @lc code=end

