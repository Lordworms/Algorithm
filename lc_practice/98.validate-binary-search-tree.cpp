/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool check(TreeNode *cur, long down, long up) {
      if (cur == nullptr) return true;
      if (cur->val >= up || cur->val <= down) return false;
      return check(cur->left, down, cur->val) && check(cur->right, cur->val, up);
    }
    bool isValidBST(TreeNode* root) {
      return check(root, LONG_MIN, LONG_MAX);    
    }
};
// @lc code=end

