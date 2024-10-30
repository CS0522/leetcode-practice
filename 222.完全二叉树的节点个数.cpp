/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
// Definition for a binary tree node.
#include <queue>
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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> qe;
        if (root)
            qe.push(root);
        // 计数
        int node_cnt = 0;
        while (!qe.empty())
        {
            int node_num = qe.size();
            for (int i = 0; i < node_num; ++i)
            {
                TreeNode *tmp = qe.front();
                qe.pop();
                // 计数
                ++node_cnt;
                if (tmp->left)
                    qe.push(tmp->left);
                if (tmp->right)
                    qe.push(tmp->right);
            }
        }

        return node_cnt;
    }
};
// @lc code=end

