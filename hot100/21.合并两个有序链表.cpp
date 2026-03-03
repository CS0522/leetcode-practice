/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 * 解决思路: 穿针引线、递归、迭代
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2)
            return (!list1 ? list2 : list1);

        ListNode *head = (list1->val <= list2->val ? list1 : list2);
        ListNode *p1 = list1, *p2 = list2;
        ListNode *pre = nullptr;
        ListNode *tmp = nullptr;
        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                pre = p1;
                p1 = p1->next;
                continue;
            }
            // 如果一开始 p1 > p2，那么 pre 就为空
            if (pre)
                pre->next = p2;
            tmp = p1;
            p1 = p2;
            p2 = tmp;
        }
        // 最终一定是 p1 到达末尾。如果 p2 还有元素，那么 pre 后面接 p2
        if (p2)
            pre->next = p2;

        return head;
    }
};

// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else 
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// 迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};
// @lc code=end

