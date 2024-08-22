/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty())
        {
            int node_num = qe.size();
            int max_of_level = qe.front()->val;

            for (int i = 0; i < node_num; i++)
            {
                auto tmp = qe.front();
                qe.pop();

                if (max_of_level < tmp->val)
                    max_of_level = tmp->val;
                
                if (tmp->left)
                    qe.push(tmp->left);
                if (tmp->right)
                    qe.push(tmp->right);
            }

            res.push_back(max_of_level);
        }

        return res;
    }
};
// @lc code=end

