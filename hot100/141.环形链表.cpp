/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 * 解决思路: 哈希集合、快慢指针（追及问题）
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> node_set;
        ListNode *p = head;
        while (p)
        {
            if (node_set.count(p))
                return true;
            node_set.insert(p);
            p = p->next;
        }
        return false;
    }
};

// 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
// @lc code=end

