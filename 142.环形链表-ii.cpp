/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
        // 哈希集合保存已经出现过的指针
        ListNode *p = head;
        std::unordered_set<ListNode*> us;

        while (p != nullptr)
        {
            // 如果哈希集合中存在这个指针
            if (us.count(p))
                return p;
            // 不存在
            us.insert(p);
            p = p->next;
        }
        // 遍历结束，没有环
        return p;
    }
};
// @lc code=end

