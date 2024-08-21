/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void preOrder(TreeNode *root, vector<int> &res)
    {
        // 递归终止
        if (root == nullptr)
            return;
        // 中左右
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // preOrder(root, res);
        // return res;

        // 迭代法
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr)
            return res;
        // 加入根节点
        st.push(root);
        while (!st.empty())
        {
            auto p = st.top();
            st.pop();
            res.push_back(p->val);
            // 空值不入栈
            if (p->right) 
                st.push(p->right);
            if (p->left) 
                st.push(p->left); 
        }

        return res;
    }
};
// @lc code=end
