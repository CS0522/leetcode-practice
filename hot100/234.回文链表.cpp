/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 * 解决思路：O(N) 数组、翻转后半列表法
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        ListNode* p = head;
        while (p)
        {
            vals.push_back(p->val);
            p = p->next;
        }
        int vals_size = vals.size();
        for (int i = 0; i < vals_size/2; i++)
        {
            if (vals[i] != vals[vals_size - 1 - i])
                return false;
        }
        return true;
    }
};
// @lc code=end

