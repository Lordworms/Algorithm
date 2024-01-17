/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
 private:
  string s;
  int max_dep = 0;
 public:
  void get_dep(TreeNode *cur, int cur_dep) {
    max_dep = max(max_dep, cur_dep);
    if (cur->left == nullptr && cur->right == nullptr) return;
    if (cur->left) get_dep(cur->left, cur_dep + 1);
    if (cur->right) get_dep(cur->right, cur_dep + 1);
  }
  void dfs(TreeNode* cur, int cur_dep) {
    if (s.size() != 0) {
      s += ',';
    }
    
    if (cur != nullptr) {
      s += to_string(cur->val);
    } else {
      s += "null";
    }
    if (cur_dep == max_dep) return;
    if (cur == nullptr) return;
    dfs(cur->left, cur_dep + 1);
    dfs(cur->right, cur_dep + 1);
  }
  TreeNode* reload(int& cur, string& data, int cur_dep) {
    while (data[cur] == ',' || data[cur] == ' ') ++cur;
    int r = cur;
    while (r < data.size() && data[r] != ',') ++r;
    string tmp = data.substr(cur, r - cur);
    TreeNode *root;
    if (tmp != "null") {
      root = new TreeNode(atoi(tmp.c_str()));
    } else {
      root = nullptr;
    }
    cur = r;
    if (cur_dep == max_dep) return root;
    if (root != nullptr) {
      root->left = reload(cur, data, cur_dep + 1);
      root->right = reload(cur, data, cur_dep + 1);
    }
    return root;
  }
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    s = "";
    get_dep(root, 0);
    dfs(root, 0);
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) { int cur = 0;return reload(cur, data, 0); }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
int main() { 
  int n = 7;
  vector<TreeNode*> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = new TreeNode(i);
  }
  a[1]->left = a[2];
  a[1]->right = a[3];
  a[3]->left = a[4];
  a[3]->right = a[5];
  Codec sol;
  string s = sol.serialize(a[1]);
  auto k = sol.deserialize(s);
  return 0;
}
