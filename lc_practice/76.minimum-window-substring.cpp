/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string minWindow(string s, string t) {
    map<char, int> cur_window, stand;
    for (auto &c : t) {
      stand[c]++;
    }
    function<bool()> check = [&]() {
      for (auto &k : stand) {
        if (cur_window[k.first] < k.second) {
          return false;
        }
      }
      return true;
    };
    int n = s.size();
    int l = 0, len = INT_MAX, st = -1;
    for (int r = 0; r < n; ++r) {
      if (stand.find(s[r]) != stand.end()) {
        cur_window[s[r]]++;
      }
      while (l <= r && check()) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          st = l;
        }
        if (stand.find(s[l]) != stand.end()) cur_window[s[l]]--;
        ++l;
      }
    }
    return st == -1 ? "" : s.substr(st, len);
  }
};
// int main() {
//   Solution sol;
//   sol.minWindow("ADOBECODEBANC", "ABC");
// }
// @lc code=end
