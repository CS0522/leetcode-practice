/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // result
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        // queue
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty())
        {
            int node_num = qe.size();
            vector<int> level_traverse;
            for (int i = 0; i < node_num; i++)
            {
                auto tmp = qe.front();
                qe.pop();
                level_traverse.push_back(tmp->val);

                if (tmp->left)
                    qe.push(tmp->left);
                if (tmp->right)
                    qe.push(tmp->right);
            }

            res.push_back(level_traverse);
        }

        // 相比于正序遍历只需要倒序第一维
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

