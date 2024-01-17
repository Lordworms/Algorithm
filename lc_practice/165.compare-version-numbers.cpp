/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int compareVersion(string version1, string version2) {
    int n1 = version1.size(), n2 = version2.size();
    int l1 = 0, l2 = 0;
    auto get_v = [&](int &l1, string &version1) {
      string t1;
      bool beg_zero_1 = true;
      if (version1[l1] == '.') ++l1;
      while (l1 < version1.size() && version1[l1] != '.') {
        if (version1[l1] == '0') {
          if (!beg_zero_1) {
            t1 += version1[l1];
          }
        } else {
          t1 += version1[l1];
          beg_zero_1 = false;
        }
        ++l1;
      }
      return atoi(t1.c_str());
    };
    while (l1 < n1 && l2 < n2) {
      auto v1 = get_v(l1, version1);
      auto v2 = get_v(l2, version2);
      if (v1 < v2)
        return -1;
      else if (v2 < v1)
        return 1;
    }
    auto check = [&] (int &l1, string &version1) {
      int n = version1.size();
      int v = 0;
      while (v == 0 && l1 < n) {
        v = get_v(l1, version1);
        if (v > 0) return 1;
      }
      return 0;
    };
    if (l1 < n1 && check(l1, version1)) {
      return 1;
    }
    if (l2 < n2 && check(l2, version2)) {
      return -1;
    }
    return 0;
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   assert(-1 == sol.compareVersion("1.1", "1.10"));
// //   assert(1 == sol.compareVersion("1.0.1", "1"));
// }
