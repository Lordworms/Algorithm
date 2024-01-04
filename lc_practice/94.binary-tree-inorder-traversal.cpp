/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<int> res;
public:
    void travel(TreeNode *r) {
      if (r == nullptr) return;
      if (r->left) travel(r->left);
      res.push_back(r->val);
      if (r->right) travel(r->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
      travel(root);
      return res;  
    }
};
// @lc code=end

