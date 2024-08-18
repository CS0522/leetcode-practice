/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        // 新建头节点
        ListNode *head_node = new ListNode(-1, head);
        // 前一个节点
        ListNode *pre = head_node;
        // 当前节点
        ListNode *curr = head;

        while (curr != nullptr)
        {
            // 下一个节点
            ListNode *post = curr->next;
            // post 不为 null
            if (post != nullptr)
            {
                curr->next = post->next;
                post->next = curr;
                pre->next = post;
            }
            // forward
            pre = curr;
            curr = curr->next;
        }

        return head_node->next;
    }
};
// @lc code=end

