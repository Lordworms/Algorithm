/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      // the biggest value that length of i ends with
      if (n == 0) return n;
      vector<int> dp(n + 1, 0);
      int len = 1;
      dp[len] = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > dp[len]) {
          dp[++len] = nums[i];
          continue;
        }     
        int l = 1, r = len, pos = 0;
        while (l <= r) {
          int m = (l + r) >> 1;
          if (dp[m] < nums[i]) {
            pos = m;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        dp[pos + 1] = nums[i];
      }
      return len;
    }
};
// @lc code=end
// int main() {
//   vector<int> a = {10,9,2,5,3,4};
//   Solution sol;
//   assert(sol.lengthOfLIS(a) == 3);
// }

