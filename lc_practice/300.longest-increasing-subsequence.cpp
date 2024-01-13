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
      if (n <= 1) return n; 
      vector<int> dp(n + 1, 0);
      int len = 0;
      dp[++len] = nums[0];
      for (int i = 1; i < n; ++i) {
        if (nums[i] > dp[len]) {
          dp[++len] = nums[i];
        }
        int l = 1, r = len, ans = 0;
        while (l <= r) {
          int m = (l + r) >> 1;
          if (dp[m] < nums[i]) {
            ans = m;
            l = m + 1;  
          } else {
            r = m - 1;
          }
        }
        dp[ans + 1] = nums[i];
      }
      return len;
    }
};
// @lc code=end
int main() {
  vector<int> a = {-2, -1};
  Solution sol;
  assert(sol.lengthOfLIS(a) == 1);
}

