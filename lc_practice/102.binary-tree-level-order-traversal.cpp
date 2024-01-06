#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
      if (root == nullptr) return vector<vector<int>>();
      map<TreeNode*, int> depth;
      depth[root] = 0;
      int total_dep = 0;
     function<void(TreeNode*, int)> dfs = [&](TreeNode *r, int dep) {
        depth[r] = dep;
        total_dep = max(total_dep, dep);
        if (r->left != nullptr) {
            dfs(r->left, dep + 1);
        }
        if (r->right != nullptr) {
            dfs(r->right, dep + 1);
        }  
      };
      dfs(root, 0);
      vector<vector<int>> ans(total_dep + 1);
      for (auto &p : depth) {
        ans[p.second].push_back(p.first->val);
      } 
      return ans;
    }
};
// @lc code=end
int main() {
  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  Solution sol;
  sol.levelOrder(root);
}
