/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      map<int, int> cnt;
      for (int i = 0; i < nums.size(); ++i) {
        cnt[nums[i]] += nums[i];
      } 
      vector<int> a(1e4 + 1);
      for (auto &p : cnt) {
        a[p.first] += p.second;
      }
      vector<int> dp(1e4 + 1);
      dp[1] = a[1], dp[2] = max(a[1], a[2]);
      for (int i = 3; i <= 1e4; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
      }
      return dp[1e4];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {3, 1};
//   sol.deleteAndEarn(a);
// }
