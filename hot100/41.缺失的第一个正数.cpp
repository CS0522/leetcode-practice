/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
// 时间复杂度偏高
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(), nums.end()); // O(Nlog(N))
//         size_t nums_size = nums.size();
//         size_t res = 1;
//         bool has_1 = false;
//         for (size_t i = 0; i < nums_size; i++)
//         {
//             if (nums[i] == 1)
//                 has_1 = true;
//             if (nums[i] <= 2)
//                 continue;
//             if (i > 0 && (nums[i] - nums[i - 1] > 1))
//             {
//                 res = nums[i - 1] + 1;
//                 break;
//             }
//         }
//         cout << res << endl;
//         if (res == 1)
//             res = size_t(nums[nums_size - 1]) + 1;
//         if (!has_1)
//             res = 1;
//         return (int)res; 
//     }
// };


// @lc code=end

