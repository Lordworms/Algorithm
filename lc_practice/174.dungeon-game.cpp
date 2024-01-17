/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int n = dungeon.size(), m = dungeon[0].size();
      // dp[i][j] is the minimal positive health you should get in order to get [i][j]
      vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0x3f3f3f3f));
      dp[n][m] = 1;
      dp[n - 1][m] = 1;
      dp[n][m - 1] = 1;
      for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
          int cur_min = min(dp[i + 1][j], dp[i][j + 1]);
          dp[i][j] = std::max({cur_min - dungeon[i][j], 1});
        }
      }
      return dp[0][0];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<vector<int>> a = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
//   sol.calculateMinimumHP(a);
// }

