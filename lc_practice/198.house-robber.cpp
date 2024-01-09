/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n);
      dp[0] = nums[0];
      if (n == 1) {
        return dp[0];
      }
      dp[1] = max(nums[0], nums[1]);
      if (n == 2) {
        return dp[1];
      }
      for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);  
      }
      return dp[n - 1];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {1, 2, 3, 1};
//   sol.rob(a);
// }

