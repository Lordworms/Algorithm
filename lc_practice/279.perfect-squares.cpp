/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
      vector<int> dp(n + 1, 1e8);
      vector<int> sqare;
      for (int i = 1; i * i <= n; ++i) {
        sqare.push_back(i * i);
      }
      dp[0] = 0;
      for (int i = 1; i <= n; ++i) {
        for (auto &c : sqare) {
          if (c > i) break;
          if (dp[i - c] == 1e8) {
            continue;  
          }
          dp[i] = min(dp[i - c] + 1, dp[i]);
        }
      }
      return dp[n];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.numSquares(12);
// }

