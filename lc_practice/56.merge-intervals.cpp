/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& interv) {
    int l = -1, r = -1;
    sort(interv.begin(), interv.end());
    vector<vector<int>> ans;
    for (int i = 0; i < interv.size(); ++i) {
      auto& p = interv[i];
      if (p[0] > r) {
        if (!(l == -1 && r == -1)) {
          ans.push_back({l, r});
        }
        l = p[0], r = p[1];
      } else {
        r = max(r, p[1]);
      }
      if (i == interv.size() - 1) {
        ans.push_back({l, r});
      }
    }
    return ans;
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<vector<int>> interv = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
//   sol.merge(interv);
// }
