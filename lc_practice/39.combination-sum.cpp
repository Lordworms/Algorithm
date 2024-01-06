/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int target;
    vector<vector<int>> ans;
public:
    void dfs(vector<int> &tmp, vector<int> &can, int sum, int cur) {
      if (cur == can.size()) {
        return;
      }  
      if (sum == target) {
        ans.push_back(tmp);  
        return;
      }
      dfs(tmp, can, sum, cur + 1);
      if (sum + can[cur] <= target) {
        tmp.push_back(can[cur]);
        dfs(tmp, can, sum + can[cur], cur); // could pick up multiple times
        tmp.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      this->target = target;
      vector<int> tmp;
      dfs(tmp ,candidates, 0, 0);    
      return ans;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {2, 3, 6, 7};
//   sol.combinationSum(a, 7);
// }
