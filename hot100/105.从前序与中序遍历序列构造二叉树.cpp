/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 * 解决思路: 前序遍历的第一个元素是根节点，在中序遍历中找到根节点的位置，左边的元素是左子树，右边的元素是右子树。递归构造左右子树
 *          用哈希表存储中序遍历中每个元素的位置，避免每次都要 find()
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
  unordered_map<int, int> in_idx_mp;

public:
    TreeNode* build(vector<int>& pre, vector<int>& in, 
                    int pre_start, int pre_end, 
                    int in_start, int in_end)
    {
      if (pre_start > pre_end)
        return nullptr;
      
      TreeNode* root = new TreeNode(pre[pre_start]);
      int idx_in = in_idx_mp[root->val];
      // int idx_in = find(in.begin(), in.end(), root->val) - in.begin();
      int left_node_num = idx_in - in_start;
      
      root->left = build(pre, in, 
                          pre_start + 1, pre_start + left_node_num,
                          in_start, in_start + left_node_num - 1);
      root->right = build(pre, in, 
                          pre_start + left_node_num + 1, pre_end, 
                          in_start + left_node_num + 1, in_end);   
      return root;           
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 省去 find() 步骤
        for (int i = 0; i < inorder.size(); i++)
          in_idx_mp[inorder[i]] = i;
        
        TreeNode* root = build(preorder, inorder, 
                               0, preorder.size() - 1,
                               0, inorder.size() - 1);
        return root;
    }
};
// @lc code=end

