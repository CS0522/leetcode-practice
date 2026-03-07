/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 * 解决思路: map 存储 <val, cnt>，需要特殊考虑相同值
 *         最优解: 自底向上分治 + 归并排序
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
    ListNode* sortList(ListNode* head) {
        map<int, int> mp;
        ListNode* p = head;
        while (p)
        {
            mp[p->val]++;
            p = p->next;
        }
        p = head;
        for (auto ele : mp)
        {
            while (ele.second)
            {
                p->val = ele.first;
                p = p->next;
                ele.second--;
            }
        }
        return head;
    }
};

// 最优解
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
            return head;

        int length = 0;
        ListNode* p = head;
        while (p)
        {
            p = p->next;
            length++;
        }
        ListNode* dummy = new ListNode(0, head);
        for (int sub_len = 1; sub_len < length; sub_len *= 2)
        {
            // 对每次分治，都每次处理两个 sub 截取并排序后，
            // 在对后面的每 2 个进行截取并排序。
            // 而不是一次性截取、再一次性排序
            ListNode* prev = dummy, *curr = prev->next;
            while (curr)
            {
                ListNode* head1 = curr;
                for (int i = 1; i < sub_len && curr->next; i++)
                    curr = curr->next;
                ListNode* head2 = curr->next;
                // head1 与 head2 之间截断
                curr->next = nullptr;
                curr = head2;
                
                if (curr)
                    for (int i = 1; i < sub_len && curr->next; i++)
                        curr = curr->next;
                ListNode *next = nullptr;
                // head2 与剩下部分之间截断
                if (curr)
                {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode *merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next)
                    prev = prev->next;
                // 处理剩下部分
                curr = next;
            }
        }
        return dummy->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummy = new ListNode();
        ListNode* tmp = dummy;
        ListNode* tmp1 = head1, *tmp2 = head2;
        while (tmp1 && tmp2)
        {
            if (tmp1->val <= tmp2->val)
            {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            }
            else
            {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if (tmp1)
            tmp->next = tmp1;
        else if (tmp2)
            tmp->next = tmp2;
        return dummy->next;
    }
};
// @lc code=end

