/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针
        // 添加头节点
        ListNode* head_node = new ListNode(-1, head);
        // 初始化快慢指针
        ListNode* slow = head_node;
        ListNode* fast = slow;
        while (n >= 0)
        {
            fast = fast->next;
            --n;
        }
        // 遍历
        while (fast != nullptr)
        {
            // forward
            fast = fast->next;
            slow = slow->next;
        }
        // fast 指向表尾 nullptr
        // slow 指向待删除元素前驱
        ListNode* target = slow->next;
        slow->next = target->next;
        delete target;

        return head_node->next;
    }
};
// @lc code=end

