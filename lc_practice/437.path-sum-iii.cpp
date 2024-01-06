/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int rootSum(TreeNode* cur, long target) {
      if (cur == nullptr) return 0;
      int res = 0;
      if (cur->val == target) ++res;
      res += rootSum(cur->left, target - cur->val);
      res += rootSum(cur->right, target - cur->val);
      return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
      if (root == nullptr) return 0;
      int res = rootSum(root, targetSum);
      res += pathSum(root->left, targetSum);
      res += pathSum(root->right, targetSum);
      return res;
    }
};
// @lc code=end

