/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int sum = p->val + q->val;
        int lower_bounder = p->val < q->val ? p->val : q->val;
        int upper_bounder = sum - lower_bounder;
        // 从上往下遍历，如果 root->val 位于 [p, q] 内，则为最近公共祖先
        if ((root->val >= lower_bounder) && (root->val <= upper_bounder))
            return root;
        
        if (root->val < p->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return NULL;
    }
};
// @lc code=end

