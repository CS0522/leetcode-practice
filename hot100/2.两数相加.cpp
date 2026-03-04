/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * 解决思路: 哨兵节点存储进位
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // head 存储进位
        ListNode* head = new ListNode();
        ListNode* p = head, *p1 = l1, *p2 = l2;
        while (p1 || p2)
        {
            int num = 0;
            if (p1)
                num += p1->val;
            if (p2)
                num += p2->val;
            num += head->val;
            p->next = new ListNode(num % 10);
            head->val = num / 10;

            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
            p = p->next;
        }
        if (head->val)
        {
            p->next = new ListNode(head->val);
            head->val = 0;
        }
        return head->next;
    }
};
// @lc code=end

