/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  vector<int> tmp;
  vector<vector<int>> ans;
  int n;

 public:
  void dfs(vector<int> &tmp, vector<int> &nums, int pos) {
    if (pos == nums.size()) {
      ans.push_back(tmp);
      return;
    }
    tmp.push_back(nums[pos]);
    dfs(tmp, nums, pos + 1);
    tmp.pop_back();
    dfs(tmp, nums, pos + 1);
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    dfs(tmp, nums, 0);
    return ans;
  }
};
// @lc code=end
int main() {
  Solution sol;
  vector<int> num = {1, 2, 3};
  sol.subsets(num);
}
