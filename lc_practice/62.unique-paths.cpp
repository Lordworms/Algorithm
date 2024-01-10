/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector dp(m + 1, vector<int> (n + 1));
      dp[1][1] = 1;
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          dp[i][j] += dp[i - 1][j] + dp[i][j - 1];     
        }
      }
      return dp[m][n];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   assert(sol.uniquePaths(3, 7) == 28);
// }

