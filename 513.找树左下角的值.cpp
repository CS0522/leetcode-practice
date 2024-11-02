/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        // 层序遍历
        // 记录遍历的每层的第一个
        queue<TreeNode*> qe;
        qe.push(root);
        int first_of_layer = root->val;
        while (!qe.empty())
        {
            int node_num = qe.size();
            for (int i = 0; i < node_num; ++i)
            {
                TreeNode *tmp = qe.front();
                qe.pop();

                if (tmp->left)
                    qe.push(tmp->left);
                if (tmp->right)
                    qe.push(tmp->right);

                // 记录每层第一个
                if (i == 0)
                    first_of_layer = tmp->val;
            }
        }

        return first_of_layer;
    }
};
// @lc code=end

