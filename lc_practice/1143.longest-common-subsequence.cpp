/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
      int n = s1.size(), m = s2.size();
      vector dp(n + 1, vector<int>(m + 1));
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;    
          } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
      return dp[n][m];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.longestCommonSubsequence("abcde", "ace");
// }

