/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 * 解决思路: 递归比较左右子树
 *          迭代法
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

class Solution {
public:
    bool compareTree(TreeNode* t1, TreeNode* t2)
    {
      if (!t1 && !t2)
        return true;
      if ((t1 && t2) && t1->val == t2->val)
        return (compareTree(t1->left, t2->right) && compareTree(t1->right, t2->left));
      return false;
    }
    bool isSymmetric(TreeNode* root) {
        return compareTree(root->left, root->right);
    }
};

// 迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode* t1, *t2;
        while (!q.empty())
        {
          t1 = q.front();
          q.pop();
          t2 = q.front();
          q.pop();
          if (!t1 && !t2)
            continue;
          if ((!t1 || !t2) || (t1->val != t2->val))
            return false;
          // t1, t2 非空
          q.push(t1->left);
          q.push(t2->right);
          q.push(t1->right);
          q.push(t2->left);
        }
        return true;
    }
};
// @lc code=end

