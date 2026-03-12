/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 * 解决思路: 迭代法中序遍历
 *          
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty())
        {
          while (p)
          {
            st.push(p);
            p = p->left;
          }
          p = st.top();
          st.pop();
          k--;
          if (k == 0)
            break;
          p = p->right;
        }
        // p 指向对应节点
        return p->val;
    }
};
// @lc code=end

