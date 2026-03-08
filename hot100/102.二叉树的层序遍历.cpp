/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <map>
using namespace std;

class Solution {
public:
    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        // result
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        // <node, level>
        queue<pair<TreeNode*, int>> qe;
        qe.push(make_pair<>(root, 0));
        int curr_level = -1;
        while (!qe.empty())
        {
            auto p = qe.front();
            qe.pop();
            // 遍历到新的层
            if (curr_level != p.second)
            {
                vector<int> tmp;
                res.push_back(tmp);
            }
            // 加入结果集
            res[res.size() - 1].push_back(p.first->val);
            // 加入队列
            if (p.first->left)
                qe.push(make_pair<>(p.first->left, p.second + 1));
            if (p.first->right)
                qe.push(make_pair<>(p.first->right, p.second + 1));

            curr_level = p.second;
        }

        return res;
    }
    */

    vector<vector<int>> levelOrder(TreeNode* root) {
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

        return res;
    }
};
// @lc code=end

