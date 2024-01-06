/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    priority_queue<int> q; 
    int k;
public:
    void travel(TreeNode *cur) {
      if (cur == nullptr) return;
      if (q.size() < k) {
        q.push(cur->val);
      } else if (cur->val < q.top()) {
        q.pop();
        q.push(cur->val);
      }
      travel(cur->left);
      travel(cur->right);
    }
    int kthSmallest(TreeNode* root, int k) {
      this->k = k;
      travel(root);
      return q.top();    
    }
};
// @lc code=end

