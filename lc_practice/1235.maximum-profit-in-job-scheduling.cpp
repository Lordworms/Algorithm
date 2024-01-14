/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  struct Job {
    int st, end, pro;
  };
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int n = startTime.size();
    vector<Job> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      a[i].st = startTime[i - 1];
      a[i].end = endTime[i - 1];
      a[i].pro = profit[i - 1];
    }
    sort(a.begin() + 1, a.end(), [&](Job a, Job b) { return a.end < b.end; });
    vector<int> dp(n + 1);
    dp[1] = a[1].pro;
    for (int i = 1; i <= n; ++i) {
      int l = 1, r = i - 1, pos = -1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m].end <= a[i].st) {
          pos = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      if (pos == -1) {
        dp[i] = max(dp[i - 1], a[i].pro);
      } else {
        dp[i] = max(dp[i - 1], dp[pos] + a[i].pro);
      }
    }
    return dp[n];
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> st = {1,2,3,3};
//   vector<int> ed = {3,4,5,6};
//   vector<int> pro = {50,10,40,70};
//   sol.jobScheduling(st, ed, pro);
// }