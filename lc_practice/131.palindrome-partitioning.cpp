/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
      int n = s.size();
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
      }
      for (int i = 0; i < n - 1; ++i) {
       if (s[i] == s[i + 1]) {
         dp[i][i + 1] = 1;
       }
      }
      for (int len = 3; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
          int j = i + len - 1;
          dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
        }
      }
      vector<vector<string>> ans;
      vector<string> tmp;
      function<void(int)> dfs = [&](int cur) {
        if (cur == s.size()) {
          ans.push_back(tmp);
          return;
        }
        for (int len = 1; cur + len - 1 < n; ++len) {
          int j = cur + len - 1;
          if (dp[cur][j]) {
            tmp.push_back(s.substr(cur, len));
            dfs(j + 1);
            tmp.pop_back();
          }
        }
      };
      dfs(0);
      return ans;
    }
};
// @lc code=end
int main() {
  Solution sol;
  sol.partition("aab");
}

