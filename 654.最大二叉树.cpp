/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // @return max index
    int findMaxIndex(vector<int>& nums, 
                    const int& start, const int& end)
    {
        int max_index = start;
        int max_num = nums[start];
        for (int i = start; i < end; i++)
        {
            if (nums[i] > max_num)
            {
                max_index = i;
                max_num = nums[i];
            }
        }
        return max_index;
    }

    void constructTree(TreeNode* &root, vector<int>& nums, 
                        const int& start, const int& end)
    {
        if (!(end - start))
            return;
        // 1. 找到当前数组中最大的元素
        int max_index = findMaxIndex(nums, start, end);
        if (root == nullptr)
            root = new TreeNode(nums[max_index]);
        // 2. 左数组构造左子树
        constructTree(root->left, nums, start, max_index);
        // 3. 右数组构造右子树
        constructTree(root->right, nums, max_index + 1, end);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = nullptr;
        constructTree(root, nums, 0, nums.size());
        return root;
    }
};
// @lc code=end

