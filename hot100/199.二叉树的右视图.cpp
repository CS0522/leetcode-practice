/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 * 解决思路: 层序遍历，记录每层最后一个元素
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root)
          q.push(root);
        while (!q.empty())
        {
          int q_size = q.size();
          for (int i = 0; i < q_size; i++)
          {
            root = q.front();
            q.pop();
            if (i == q_size - 1)
              res.push_back(root->val);
            if (root->left)
              q.push(root->left);
            if (root->right)
              q.push(root->right);
          }
        }
        return res;
    }
};
// @lc code=end

