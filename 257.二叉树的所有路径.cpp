/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     void getPaths(TreeNode* root, vector<string> &res)
//     {
//         // 递归终止条件
//         if (!root)
//             return;
//         string curr_path;
//         // 取出当前路径
//         if (!res.size())
//             curr_path = to_string(root->val);
//         else
//         {
//             curr_path = res[res.size() - 1] + "->" + to_string(root->val);
//             res.pop_back();
//         }
//         // 压入当前路径
//         if (root->left)
//         {
//             res.push_back(curr_path);
//             getPaths(root->left, res);
//         }
//         if (root->right)
//         {
//             res.push_back(curr_path);
//             getPaths(root->right, res);
//         }
//         if (!root->left && !root->right)
//             res.push_back(curr_path);
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> res;
//         getPaths(root, res);

//         return res;
//     }
// };

class Solution {
private:

    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // 中
        if (cur->left == NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result); // 左
        if (cur->right) traversal(cur->right, path + "->", result); // 右
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;

    }
};
// @lc code=end

