/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 * 解决思路: 哈希存储 <old_node*, new_node*>
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// 优化版
class Solution {
public:
    Node *copyRandomList(Node *head) {        
        unordered_map<Node*, Node*> mp;
        for (auto p = head; p; p = p->next) {
            mp[p] = new Node(p->val);            
        }
        for (auto p = head; p; p = p->next) {
            mp[p]->next = mp[p->next];
            mp[p]->random = mp[p->random];
        }  
        return mp[head];
    }
};

// @lc code=end

