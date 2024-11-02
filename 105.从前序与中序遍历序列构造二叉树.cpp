/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

class Solution {
public:
    TreeNode* build_tree(vector<int>& preorder, vector<int>& inorder, 
                        int inorder_start, int inorder_end)
    {
        if ((inorder_end - inorder_start) == 0)
            return nullptr;
        // 前序遍历的最后一个节点为当前的根节点
        int root_val = preorder[0];
        preorder.erase(preorder.begin());
        TreeNode* root = new TreeNode(root_val);
        // 前序遍历顺序：根左右，反构造时先构造左节点
        // 分割中序遍历
        vector<int>::iterator root_iter = find(inorder.begin() + inorder_start, inorder.begin() + inorder_end, root_val);
        int root_index = root_iter - inorder.begin();

        root->left = build_tree(preorder, inorder, inorder_start, root_index);
        root->right = build_tree(preorder, inorder, root_index + 1, inorder_end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build_tree(preorder, inorder, 0, inorder.size());
    }
};
// @lc code=end

