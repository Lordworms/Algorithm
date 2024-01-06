/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* construct(vector<int> &nums, int l, int r) {
      if (l > r) return nullptr;
      int m = (l + r) >> 1;
      TreeNode *cur = new TreeNode(nums[m]);
      cur->left = construct(nums, l, m - 1);
      cur->right = construct(nums, m + 1, r);
      return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return construct(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

