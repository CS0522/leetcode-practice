/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 * 解决思路: 前缀和，类似于两数之和（这里是 curr - prefix = targetsum），注意回溯问题
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
    // <前缀和, 次数> 
    unordered_map<size_t, size_t> prefix_cnt;
    
    int dfs(TreeNode* root, size_t curr, size_t targetSum)
    {
      if (!root)
        return 0;
      
      int ret = 0;
      curr += root->val;
      if (prefix_cnt.count(curr - targetSum))
        ret = prefix_cnt[curr - targetSum];

      prefix_cnt[curr]++;
      ret += dfs(root->left, curr, targetSum);
      ret += dfs(root->right, curr, targetSum);
      prefix_cnt[curr]--;

      return ret;
    }
    
    int pathSum(TreeNode* root, size_t targetSum) {
        prefix_cnt[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
// @lc code=end

