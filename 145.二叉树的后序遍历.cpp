/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <algorithm>
using namespace std;

class Solution
{
public:
    void postOrder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        // 左右中
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // postOrder(root, res);
        // return res;

        // 迭代法
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr)
            return;
        st.push(root);
        while (!st.empty())
        {
            auto p = st.top();
            st.pop();
            res.push_back(p->val);
            // 空值不入栈
            if (p->left) 
                st.push(p->left);
            if (p->right) 
                st.push(p->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
