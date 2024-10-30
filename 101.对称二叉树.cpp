/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

// class Solution {
// public:
//     // 比较两个树是否相同
//     bool compareTree(TreeNode *tree1, TreeNode *tree2)
//     {
//         if (!tree1 && !tree2)
//             return true;
//         if (!tree1 || !tree2)
//             return false;
//         if (tree1->val != tree2->val)
//             return false;
//         return (compareTree(tree1->left, tree2->left) 
//                 && compareTree(tree1->right, tree2->right));
//     }

//     TreeNode *invertTree(TreeNode *root)
//     {
//         // 递归终止条件
//         if (!root)
//             return root;
//         // 递归子树
//         invertTree(root->left);
//         invertTree(root->right);
            
//         TreeNode *tmp_node = root->left;
//         root->left = root->right;
//         root->right = tmp_node;

//         return root;
//     }

//     bool isSymmetric(TreeNode* root) {
//         if (!root)
//             return false;
//         // 先反转左子树
//         TreeNode *invertLeft = invertTree(root->left);
//         // 比较左右子树是否一致
//         bool res = compareTree(invertLeft, root->right);
//         return res;
//     }
// };

class Solution {
public:
    // 比较两个树是否相同
    bool compareTree(TreeNode *tree1, TreeNode *tree2)
    {
        if (!tree1 && !tree2)
            return true;
        if (!tree1 || !tree2)
            return false;
        if (tree1->val != tree2->val)
            return false;
        return (compareTree(tree1->left, tree2->right) 
                && compareTree(tree1->right, tree2->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return false;
        // 比较两个树是否一致
        return compareTree(root->left, root->right);
    }
};
// @lc code=end

