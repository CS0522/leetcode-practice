/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void cal_left_leaves(TreeNode *root, int &res, bool is_left)
    {
        if (!root)
            return;
        cal_left_leaves(root->left, res, true);
        cal_left_leaves(root->right, res, false);
        // 叶子节点且为左
        if (!root->left && !root->right && is_left)
            res += root->val;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        cal_left_leaves(root, res, false);

        return res;
    }
};
// @lc code=end

