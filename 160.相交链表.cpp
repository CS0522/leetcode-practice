/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
        // 哈希集合
        unordered_set<ListNode*> uset;
        // 初始化哈希集合
        ListNode *p = headA;
        while (p != nullptr)
        {
            uset.insert(p);
            p = p->next;
        }
        // 遍历 headB
        p = headB;
        while (p != nullptr)
        {
            if (uset.count(p))
            {
                // 存在指向该节点的指针
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};
// @lc code=end

