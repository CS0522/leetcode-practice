/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// #include <iostream>
// #include <vector>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // int getMaxVal(TreeNode *root)
    // {
    //     TreeNode *p = root;
    //     while (p->right)
    //         p = p->right;
    //     return p->val;
    // }
    // int getMinVal(TreeNode *root)
    // {
    //     TreeNode *p = root;
    //     while (p->left)
    //         p = p->left;
    //     return p->val;
    // }
    // bool isValidBST(TreeNode* root) {
    //     bool is_left_valid = true;
    //     bool is_right_valid = true;
    //     bool is_root_valid = true;
    //     int left_max_val, right_min_val;
        
    //     if (root->left)
    //     {
    //         is_left_valid = isValidBST(root->left);
    //         left_max_val = getMaxVal(root->left);
    //     }
    //     if (root->right)
    //     {
    //         is_right_valid = isValidBST(root->right);
    //         right_min_val = getMinVal(root->right);
    //     }

    //     if (root->left)
    //         is_root_valid = is_root_valid && (root->val > left_max_val);
    //     if (root->right)
    //         is_root_valid = is_root_valid && (root->val < right_min_val);
        
    //     return (is_left_valid && is_right_valid && is_root_valid);
    // }
    void traversalBST(TreeNode* root, vector<int>& nodes)
    {
        if (!root)
            return;
        // 中序遍历
        traversalBST(root->left, nodes);
        nodes.push_back(root->val);
        traversalBST(root->right, nodes);
    }
    bool isValidBST(TreeNode* root)
    {
        vector<int> nodes;
        traversalBST(root, nodes);
        for (size_t i = 1; i < nodes.size(); i++)
        {
            if (nodes[i - 1] >= nodes[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

