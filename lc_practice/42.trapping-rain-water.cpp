/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int trap(vector<int>& h) {
    int n = h.size();
    vector<int> lmax(n), rmax(n);
    int cur_max = 0;
    for (int i = 0; i < n; ++i) {
      cur_max = max(cur_max, h[i]);
      lmax[i] = cur_max;
    }
    cur_max = 0;
    for (int i = n - 1; i >= 0; --i) {
      cur_max = max(cur_max, h[i]);
      rmax[i] = cur_max;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += min(rmax[i], lmax[i]) - h[i]; 
    }
    return ans;
  }
};
// @lc code=end
