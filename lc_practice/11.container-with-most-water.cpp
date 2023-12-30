#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& h) {
      long long ans = 0;
      int l = 0, r = h.size() - 1;
      while (l < r) {
        if (h[l] < h[r]) {
          ans = max(ans, 1ll * h[l] * (r - l));
          ++l;
        } else {
          ans = max(ans, 1ll * h[r] * (r - l));
          --r;
        }
      }
      return ans;
    }
    
};
// @lc code=end

