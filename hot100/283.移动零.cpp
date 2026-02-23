/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int len = nums.size();
//         // 快慢指针
//         int slow = 0;
//         int fast = 0;
//         while (fast < len)
//         {
//             // 右边不是 0，交换
//             if (nums[fast] != 0)
//             {
//                 swap(nums[slow], nums[fast]);
//                 slow++;
//             }
//             fast++;
//         }
//     }
// };

// 剪枝，优化不必要的交换，slow 指针指向第一个为 0 的元素
class Solution {
    public:
        // 快慢指针
        void moveZeroes(vector<int>& nums) {
            int slow = 0;
            while (nums[slow] != 0)
            {
                slow++;
                if (slow >= nums.size())
                    return;
            }
            int fast = slow;
            while (fast < nums.size())
            {
                if (fast != slow && nums[fast] != 0)
                {
                    nums[slow] = nums[fast];
                    nums[fast] = 0;
                    slow++;
                }
                fast++;
            }
        }
    };
// @lc code=end

