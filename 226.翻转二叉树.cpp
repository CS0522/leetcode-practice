/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 递归终止条件
        if (!root)
            return root;
        // 递归子树
        invertTree(root->left);
        invertTree(root->right);
            
        TreeNode *tmp_node = root->left;
        root->left = root->right;
        root->right = tmp_node;

        return root;
    }
};
// @lc code=end
