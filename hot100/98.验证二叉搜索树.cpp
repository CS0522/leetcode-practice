/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 * 解决思路: 中序遍历
 *          递归法，直接比较，设置上下限
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void traversalBST(TreeNode* root, vector<int>& nodes)
    {
        if (!root)
            return;
        // 中序遍历
        traversalBST(root->left, nodes);
        nodes.push_back(root->val);
        traversalBST(root->right, nodes);
    }
    bool isValidBST(TreeNode* root)
    {
        vector<int> nodes;
        traversalBST(root, nodes);
        for (size_t i = 1; i < nodes.size(); i++)
        {
            if (nodes[i - 1] >= nodes[i])
                return false;
        }
        return true;
    }
};

// 直接比较
class Solution {
public:
    bool isValid(TreeNode* root, long long lower, long long upper) {
      if (!root)
        return true;
      if (root->val <= lower || root->val >= upper)
        return false;
      return (isValid(root->left, lower, root->val) && 
              isValid(root->right, root->val, upper));
    }

    bool isValidBST(TreeNode* root) {
      return isValid(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

