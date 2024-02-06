/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int shipWithinDays(vector<int>& w, int d) {
    int l = *max_element(w.begin(), w.end()), r = accumulate(w.begin(), w.end(), 0);
    function<bool(int)> check = [&](int c) {
      int cur_day = 1, cur_size = 0;
      for (int i = 0; i < w.size(); ++i) {
        if (cur_size + w[i] > c) {
          ++cur_day;
          cur_size = 0;
        }
        cur_size += w[i];
      }
      return cur_day <= d;
    };
    int ans = r;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (check(m)) {
        r = m - 1;
        ans = m;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};
// @lc code=end
// int main() {
//   vector<int> w = {1,2,3,4,5,6,7,8,9,10};
//   Solution sol;
//   sol.shipWithinDays(w, 5);
// }
