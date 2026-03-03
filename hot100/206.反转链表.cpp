/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// 重新新建 Node
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        for (ListNode* x = head; x != nullptr; x = x->next) {
            // 新建 node 的 next 域指向当前 node
            // ans 指向新建 node
            // 以此达到反转指针的目的
            ans = new ListNode(x->val, ans);
        }
        return ans;
    }
};

// 迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *sub;
        while (cur)
        {
            sub = cur->next;
            cur->next = pre;
            pre = cur;
            cur = sub;
        }
        return pre;
    }
};

// 栈
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        
        stack<ListNode*> st;
        ListNode *p = head;
        while (p)
        {
            st.push(p);
            p = p->next;
        }
        ListNode *new_head = st.top();
        st.pop();
        p = new_head;
        while (!st.empty())
        {
            p->next = st.top();
            st.pop();
            p = p->next;
        }
        // 注意，防止成环
        p->next = nullptr;
        return new_head;
    }
};

// @lc code=end

