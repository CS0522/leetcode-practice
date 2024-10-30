/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
// Definition for a binary tree node.
#include <cmath>
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
//     int calHight(TreeNode* root) {
//         if (!root)
//             return 0;
//         return (max(calHight(root->left), calHight(root->right)) + 1);
//     }

//     bool isBalanced(TreeNode* root) {
//         if (!root)
//             return true;
//         // 分别递归判断左子树和右子树是否平衡，然后判断当前树是否平衡
//         if (isBalanced(root->left) && isBalanced(root->right))
//         {
//             return (fabs(calHight(root->left) - calHight(root->right)) <= 1);
//         }
//         return false;
//     }
// };

class Solution {
public:
    int calHight(TreeNode* root) {
        if (!root)
            return 0;
        int left_hight = calHight(root->left);
        int right_hight = calHight(root->right);
        if (left_hight == -1 || right_hight == -1)
            return -1;
        return (fabs(left_hight - right_hight) <= 1 ? 
                max(left_hight, right_hight) + 1 :
                -1);
    }

    bool isBalanced(TreeNode* root) {
        return (calHight(root) != -1);
    }
};
// @lc code=end

