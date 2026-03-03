/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 * 解决思路: 哈希集合、快慢指针
 * 快慢指针: L(fast) = 2k，L(slow) = k，此时 fast 与 slow 在相遇点 T 相遇；
 *          那么 slow 再走 k 后，新指针 ptr 起点同时再走 k，L(slow) = 2k，L(ptr) = k，slow 与 ptr 也会在 T 相遇；
 *          但 slow 与 ptr 走速相同，所以在环内 slow 与 ptr 以相同步长前进，即同步；
 *          所以 slow 与 ptr 在环入口就相遇。
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> node_set;
        ListNode *p = head;
        while (p)
        {
            if (node_set.count(p))
                return p;
            node_set.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};

// 快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !(head->next))
            return nullptr;
        ListNode *slow = head, *fast = head;
        fast = fast->next->next;
        slow = slow->next;
        while (fast && fast->next)
        {
            if (fast == slow)
            {
                ListNode *ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return nullptr;
    }
};
// @lc code=end

