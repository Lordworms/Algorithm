/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 
 */
#include <bits/stdc++.h>
using namespace std;
// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
private:
    map<int, map<int, int>> fa;
    map<int, int> dep;
    map<int, TreeNode*> mp; 
public:
    void dfs(TreeNode *cur, long long f) {
      int &x = cur->val;
      fa[x][0] = f;
      dep[cur->val] = dep[f] + 1;
      mp[cur->val] = cur;
      for (int i = 1; i < 31; ++i) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
      }        
      if (cur->left) {
        dfs(cur->left, cur->val);  
      }
      if (cur->right) {
        dfs(cur->right, cur->val);  
      }
    }
    TreeNode* commonFa(int x, int y) {
      if (dep[x] > dep[y]) {
        swap(x, y);
      } 
      int dif = dep[y] - dep[x];
      for (int i = 0; dif; ++i, dif >>= 1) {
        if (dif & 1) {
          y = fa[y][i];
        }  
      }
      if (x == y) return mp[x];
      for (int i = 30; i >= 0; --i) {
        if (fa[x][i] != fa[y][i]) {
          x = fa[x][i];
          y = fa[y][i];
        }
      }
      return mp[fa[x][0]];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      dfs(root, 0);
      return commonFa(p->val, q->val);
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<TreeNode*> a(6);
//   a[0] = new TreeNode(-1);
//   a[1] = new TreeNode(0);
//   a[2] = new TreeNode(3);
//   a[3] = new TreeNode(-2);
//   a[4] = new TreeNode(4);
//   a[5] = new TreeNode(8);
//   a[0]->left = a[1];
//   a[0]->right = a[2];
//   a[1]->left = a[3];
//   a[1]->right = a[4];
//   a[3]->left = a[5];
//   assert(sol.lowestCommonAncestor(a[0], a[2], a[5])->val == -1);
// }

