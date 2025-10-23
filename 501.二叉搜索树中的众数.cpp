/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int val_freq[200001] = {0};
    void traverseBST(TreeNode *root) {
        if (root == nullptr)
            return;
        traverseBST(root->left);
        val_freq[(100000 + root->val)] += 1;
        traverseBST(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        traverseBST(root);
        // find max
        int max_freq = 0;
        for (int i = 0; i < 200001; i++)
        {
            if (val_freq[i] >= max_freq)
            {
                if (val_freq[i] != max_freq)
                    res.clear();
                res.push_back(i - 100000);
                max_freq = val_freq[i];
            }
        }
        return res;
    }
};
// @lc code=end

