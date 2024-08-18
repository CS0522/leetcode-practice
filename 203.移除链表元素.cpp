/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        // 处理下一个元素，这样避免特殊处理最后一个元素
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        if (head == nullptr)
        {
            return head;
        }

        // 此时 head 元素不为 val
        // pointer
        ListNode* p = head;
        while (p->next != nullptr)
        {
            // 移除元素
            if (p->next->val == val)
            {
                auto temp = p->next;
                // 链接下下个元素
                p->next = p->next->next;
                // 释放下个元素
                delete temp;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};
// @lc code=end

