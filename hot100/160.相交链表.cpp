/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 * 解决思路：1. 哈希集合；2. 数学思路，如果有相交，遍历 m+n 次最终指针都会指向公共节点或者同时为 null
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB)
        {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA;
    }
};
// @lc code=end

