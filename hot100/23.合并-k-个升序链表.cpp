/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 * 解决思路: 多次 二路合并
 *          优化: 分治递归，降低时间复杂度
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                prev->next = list1;
                list1 = list1->next;
            }
            else
            {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = (list1) ? list1 : list2;
        return dummy->next;
    }
    // N - 1 次二路合并
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int lists_num = lists.size();
        if (!lists_num)
            return nullptr;
        ListNode *new_merged = lists[0];
        while (lists_num > 1)
        {
            new_merged = mergeTwoLists(lists[lists_num - 1], lists[lists_num - 2]);
            lists.pop_back();
            lists.pop_back();
            lists.push_back(new_merged);
            lists_num = lists.size();
        }
        return new_merged;
    }
};

// 分治版
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                prev->next = list1;
                list1 = list1->next;
            }
            else
            {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = (list1) ? list1 : list2;
        return dummy->next;
    }

    ListNode *mergePair(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        return mergeTwoLists(mergePair(lists, left, mid), mergePair(lists, mid + 1, right));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergePair(lists, 0, lists.size() - 1);
    }
};
// @lc code=end

