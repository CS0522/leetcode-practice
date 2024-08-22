/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> qe;
        if (root)
            qe.push(root);
        while (!qe.empty())
        {
            int node_num = qe.size();
            for (int i = 0; i < node_num; i++)
            {
                auto tmp = qe.front();
                qe.pop();

                // 如果没有左右子树，则该节点为叶子节点，为最短深度
                if (!tmp->left && !tmp->right)
                    return depth + 1;
                else
                {
                    if (tmp->left)
                        qe.push(tmp->left);
                    if (tmp->right)
                        qe.push(tmp->right);
                }
            }
            ++depth;
        }

        return depth;
    }
};
// @lc code=end

