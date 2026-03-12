/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 * 解决思路: 前序遍历后链接
 *          找左、右子节点的前驱节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> preOrder;
        stack<TreeNode*> st;
        if (root)
          st.push(root);
        while (!st.empty())
        {
          root = st.top();
          st.pop();
          preOrder.push_back(root);
          if (root->right)
            st.push(root->right);
          if (root->left)
            st.push(root->left);
        }
        int node_num = preOrder.size();
        TreeNode* prev = nullptr;
        for (int i = node_num - 1; i >= 0; i--)
        {
          preOrder[i]->right = prev;
          preOrder[i]->left = nullptr;
          prev = preOrder[i];
        }
        if (node_num)
          root = preOrder[0];
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr)
        {
          if (curr->left)
          {
            // curr 左子节点的前驱为 curr
            TreeNode* curr_next = curr->left;
            TreeNode* right_prev = curr->left;
            // 找到左子树中的最右下角节点，作为 curr 右子节点的前驱
            while (right_prev->right)
            {
              right_prev = right_prev->right;
            }
            right_prev->right = curr->right;
            curr->left = nullptr;
            curr->right = curr_next;
          }
          curr = curr->right;
        }
    }
};
// @lc code=end

