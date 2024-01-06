/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
class Solution {
 private:
  map<int, int> pos;
 public:
  TreeNode* build(vector<int>& pre, vector<int>& in, int in_left, int in_right,
                  int pre_left, int pre_right) {
    if (in_left > in_right) {
      return nullptr;
    }
    TreeNode* cur = new TreeNode(pre[pre_left]);
    int in_pos = pos[pre[pre_left]], siz = pos[pre[pre_left]] - in_left;
    cur->left = build(pre, in, in_left, pos[pre[pre_left]] - 1,
                      pre_left + 1, pre_left + siz);
    cur->right = build(pre, in, pos[pre[pre_left]] + 1, in_right,
                       pre_left + siz + 1, pre_right);
    return cur;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      pos[inorder[i]] = i;
    }
    int n = preorder.size();
    return build(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};
// @lc code=end
