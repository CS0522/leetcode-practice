/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void inOrder(TreeNode *root, vector<int> &res)
    {
        // 递归终止
        if (root == nullptr)
            return;
        // 左中右
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // inOrder(root, res);
        // return res;

        // 迭代法
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr || !st.empty())
        {
            // 左
            if (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            // 中、右
            else
            {
                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }

        return res;
    }
};
// @lc code=end
