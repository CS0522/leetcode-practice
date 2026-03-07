/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 * 解决思路: 结合翻转链表、直接模拟过程
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
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode *pre = tail->next;
        ListNode *cur = head;
        while (pre != tail)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = prev->next;
        
        while (curr)
        {
            ListNode* tail = prev;
            // 剩余长度是否满足 k 个
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                    return dummy->next;
            }
            ListNode* next_part = tail->next;
            auto result = reverseList(head, tail);
            head = result.first;
            tail = result.second;
            prev->next = head;
            tail->next = next_part;
            prev = tail;
            head = next_part;
        }
        return dummy->next;
    }
};
// @lc code=end

