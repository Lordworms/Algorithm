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
    int n1 = s1.size(), n2 = s2.size();
    vector dp(n1 + 1, vector<int> (n2 + 1, 0));
    dp[0][0] = 0;
    for (int i = 0; i <= n1; ++i) dp[i][0] = i;
    for (int j = 0; j <= n2; ++j) dp[0][j] = j;
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        if (s1[i - 1] != s2[j - 1]) dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        else dp[i][j] = dp[i - 1][j - 1];
      }
    }
    return dp[n1][n2];
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.minDistance("intention", "execution");
// }
