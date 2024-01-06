/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    map<int, int> dep_node, dep;
    queue<TreeNode*> q;
    vector<int> ans;
    if (root == nullptr) return ans;
    dep[0] = root->val;
    q.push(root);
    ans.push_back(root->val);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p->left) {
        dep[p->left->val] = dep[p->val] + 1;
        dep_node[dep[p->left->val]] = p->left;
        q.push(p->left);
      }
      if (p->right) {
        q.push(p->right);
        dep[p->right->val] = dep[p->val] + 1;
        dep_node[dep[p->right->val]] = p->right;
      }
    }

    for (auto& p : dep_node) {
      ans.push_back(p.second->val);
    }
    return ans;
  }
};
// @lc code=end
