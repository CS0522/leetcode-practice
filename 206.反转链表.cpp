/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        for (ListNode* x = head; x != nullptr; x = x->next) {
            // 新建 node 的 next 域指向当前 node
            // ans 指向新建 node
            // 以此达到反转指针的目的
            ans = new ListNode(x->val, ans);
        }
        return ans;
    }
};
// @lc code=end

