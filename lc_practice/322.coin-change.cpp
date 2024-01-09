/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int tar) {
      vector<int> dp(tar + 1, 1e8);
      dp[0] = 0;
      sort(coins.begin(), coins.end());
      for (int i = 1; i <= tar; ++i) {
        for (const auto &c : coins) {
          if (i == 83) {
            int k = 1;
          }
          if (c > i) break;
          if (dp[i - c] == 1e8) continue;
          dp[i] = min(dp[i - c] + 1, dp[i]); 
        }
      }
      return dp[tar] == 1e8 ? -1 : dp[tar];
    }
};
// @lc code=end
// int main() {
//   vector<int> a = {474,83,404,3};
//   Solution sol;
//   sol.coinChange(a, 264);
// }

