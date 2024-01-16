/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
      int l = 0, r = citations.size(), ans = 0;
      while (l <= r) {
        int m = (l + r) >> 1;
        int cnt = 0;
        for (int i = 0; i < citations.size(); ++i) {
          cnt += citations[i] >= m;
        }
        if (cnt >= m) {
          ans = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      return ans;
    }
};w
// int main() {
//   vector<int> a = {3,0,6,1,5};
//   Solution sol;
//   sol.hIndex(a);
// }

