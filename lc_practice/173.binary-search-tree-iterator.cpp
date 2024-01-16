/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
private:
    vector<int> val;
    int id;
public:
    void traverse(TreeNode *cur) {
      if (cur == nullptr) {
        return;
      }
      traverse(cur->left);
      val.push_back(cur->val);
      traverse(cur->right);
    }
    BSTIterator(TreeNode* root) {
      id = -1;
      traverse(root);
    }
    
    int next() {
      return val[++id];  
    }
    
    bool hasNext() {
      return id + 1 < val.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

