/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool judge(TreeNode *left, TreeNode *right) {
      if (!left && !right) return true;
      if (left && !right || right && !left) return false;
      return judge(left->right, right->left) && judge(right->right, left->left) && left->val == right->val;
    }
    bool isSymmetric(TreeNode* root) {
      return judge(root->left, root->right);      
    }
};
// @lc code=end

