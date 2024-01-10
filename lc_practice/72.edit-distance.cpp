/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minDistance(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector dp(n + 1, vector<int>(m + 1));
    if (n + m == 0) return 0;
    for (int i = 0; i <= m; ++i) {
      dp[0][i] = i;
    } 
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if(s1[i - 1] != s2[j - 1]) dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        else dp[i][j] = dp[i - 1][j - 1];
      }
    }
    return dp[n][m];
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.minDistance("", "a");
// }
