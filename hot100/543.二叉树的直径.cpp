/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 * 解决思路: 记录经过该节点的最长路径，更新全局变量。经过该节点最长路径 = 左子树深度 + 右子树深度
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
    int res = 0;
public:
    int get_max_depth(TreeNode *root)
    {
      if (!root)
        return -1;
      int left = get_max_depth(root->left) + 1;
      int right = get_max_depth(root->right) + 1;
      res = max(res, left + right);
      return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        get_max_depth(root);
        return res;
    }
};
// @lc code=end

