/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<Node*> qe;
        qe.push(root);
        while (!qe.empty())
        {
            int node_num = qe.size();
            vector<int> level_res;
            for (int i = 0; i < node_num; i++)
            {
                auto tmp = qe.front();
                qe.pop();

                level_res.push_back(tmp->val);
                
                // 加入子树
                auto children_num = tmp->children.size();
                for (int j = 0; j < children_num; j++)
                {
                    if (tmp->children[j])
                        qe.push(tmp->children[j]);
                }
            }

            res.push_back(level_res);
        }

        return res;
    }
};
// @lc code=end

