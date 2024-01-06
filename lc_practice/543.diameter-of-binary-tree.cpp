/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
private:
    int ans = 1;
public:
    int dep(TreeNode *r) {
      if (r == nullptr) return 0;
      int L = dep(r->left);
      int R = dep(r->right);
      ans = max(ans, R + L + 1);
      return max(L, R) + 1; 
    }
    int diameterOfBinaryTree(TreeNode* r) {
      dep(r);
      return ans - 1; //              
    }
};
// @lc code=end

