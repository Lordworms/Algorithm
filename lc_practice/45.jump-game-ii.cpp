/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n, n);
      dp[0] = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (j + nums[j] >= i) {
            dp[i] = min(dp[i], dp[j] + 1);
          }
        }  
      }
      return dp[n - 1];  
    }
};
// @lc code=end

