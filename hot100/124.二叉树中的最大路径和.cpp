/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 * 解决思路: 参考二叉树的直径，递归每个点，比较: 左+中+右、左+中、右+中、中，并取最大更新全局变量；
 *          然后返回左+中、右+中、中三者的最大值
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
    int res = INT_MIN;
    int get_max_path(TreeNode* root)
    {
      if (!root)
        return 0;
      int left = get_max_path(root->left);
      int right = get_max_path(root->right);
      res = max(res, max(max(left, right) + root->val, left + right + root->val));
      if (res < root->val)
        res = root->val;
      return max(max(left, right) + root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        get_max_path(root);
        return res;
    }
};
// @lc code=end

