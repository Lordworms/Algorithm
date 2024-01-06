/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    TreeNode *tail;
    void flatten(TreeNode* root) {
      if (!root) {
        return;
      }        
      if (!root->left && !root->right) {
        tail = root;
        return;
      }        
      flatten(root->left);
      TreeNode *tmp = root->right;
      if (root->left) {
        root->right = root->left;
        tail->right = tmp;
        root->left = nullptr;
      }  
      flatten(root->right);
    }
};
// @lc code=end

