/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 * 解决思路: 通过哈希表构建 <当前节点, 当前节点父节点> 映射 + 遍历映射模拟单链表相交
 *          递归查找：如果当前节点是 p 或 q，返回当前节点；
 *                  否则在左右子树中继续查找，如果左右子树都找到，则当前节点就是最近公共祖先；
 *                  如果只找到一个，则继续向上返回找到的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::unordered_map<TreeNode*, TreeNode*> node_parent_mp;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        node_parent_mp[root] = root;
        queue<TreeNode*> qe;
        if (root)
          qe.push(root);
        while (!qe.empty())
        {
          root = qe.front();
          qe.pop();
          if (root->left)
          {
            node_parent_mp[root->left] = root;
            qe.push(root->left);
          }
          if (root->right)
          {
            node_parent_mp[root->right] = root;
            qe.push(root->right);
          }
        }

        // 模拟：单链表相交
        TreeNode* pA = p, *pB = q;
        while (pA != pB)
        {
          pA = (node_parent_mp[pA] == pA) ? q : node_parent_mp[pA];
          pB = (node_parent_mp[pB] == pB) ? p : node_parent_mp[pB];
        }
        return pA;
    }
};

// 递归查找
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
          return root;
        // 左、右子树中找 p 或 q
        // 找到则返回找到的节点
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 如果左右都找到：当前 root 就是最近公共祖先
        if (left && right)
          return root;
        // 如果只找到一个: 说明不是最近的公共祖先、或者还没到公共祖先
        return left ? left : right;
    }
};
// @lc code=end

