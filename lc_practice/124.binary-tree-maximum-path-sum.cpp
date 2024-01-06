/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int max_length = INT_MIN;
public:
    int count(TreeNode *cur) {
      if (cur == nullptr) return 0;
      int left = max(0, count(cur->left));
      int right = max(0, count(cur->right));
      max_length = max(max_length, left + right + cur->val);
      return cur->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
      count(root);
      return max_length;
    }
};
// @lc code=end

