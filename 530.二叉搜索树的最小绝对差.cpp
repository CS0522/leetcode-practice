/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // 中序遍历顺序
    std::vector<int> tree_nodes;
    void traverseBST(TreeNode *root) {
        if (root == NULL)
            return;
        
        traverseBST(root->left);
        tree_nodes.push_back(root->val);
        traverseBST(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        traverseBST(root);
        for (size_t i = tree_nodes.size() - 1; i >= 1; i--) {
            if (std::abs(tree_nodes[i] - tree_nodes[i - 1]) < min_diff)
                min_diff = std::abs(tree_nodes[i] - tree_nodes[i - 1]);
        }
        return min_diff;
    }
};
// @lc code=end

