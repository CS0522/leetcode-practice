/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <algorithm>
using namespace std;

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
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         // 空节点
//         if (!inorder.size())
//             return nullptr;
//         // 后序遍历的最后一个节点为当前的根节点
//         int root_val = postorder[postorder.size() - 1];
//         postorder.pop_back();
//         TreeNode* root = new TreeNode(root_val);
//         // 后序遍历顺序：左右根，反构造时先构造右节点
//         vector<int>::iterator root_iter = find(inorder.begin(), inorder.end(), root_val);
//         vector<int> left_inorder(inorder.begin(), root_iter);
//         vector<int> right_inorder(root_iter + 1, inorder.end());
        
//         root->right = buildTree(right_inorder, postorder);
//         root->left = buildTree(left_inorder, postorder);

//         return root;
//     }
// };

class Solution {
public:
    TreeNode * build_tree(vector<int> &inorder, vector<int> &postorder, 
                        int inorder_start, int inorder_end)
    {
        // 空节点
        if ((inorder_end - inorder_start) == 0)
            return nullptr;
        // 后序遍历的最后一个节点为当前的根节点
        int root_val = postorder[postorder.size() - 1];
        postorder.pop_back();
        TreeNode *root = new TreeNode(root_val);
        // 分割中序遍历
        vector<int>::iterator root_iter = find(inorder.begin() + inorder_start, inorder.begin() + inorder_end, root_val);
        int root_index = (root_iter - inorder.begin());

        root->right = build_tree(inorder, postorder, root_index + 1, inorder_end);
        root->left = build_tree(inorder, postorder, inorder_start, root_index);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build_tree(inorder, postorder, 0, inorder.size());
    }
};
// @lc code=end

