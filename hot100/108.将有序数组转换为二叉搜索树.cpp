/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 * 解决思路: BST 中序遍历即为升序列；BST 满足平衡要求，因此取中间元素为根节点，那么左右两边即可平衡
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
    TreeNode* createBST(vector<int>& nums, int left, int right)
    {
      if (left >= right)
        return nullptr;
      int mid = (left + right) / 2;
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = createBST(nums, left, mid);
      root->right = createBST(nums, mid + 1, right);
      return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = createBST(nums, 0, nums.size());
        return root;
    }
};
// @lc code=end

