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
    map<char, int> pat, mod;
    for (auto &c : t) {
      pat[c]++;
    }
    auto check = [&] () {
      for (auto &p : pat) {
        if (mod[p.first] < p.second) {
          return false;
        }
      }
      return true;
    };
    int len = INT_MAX, st = -1, l = 0;
    for (int r = 0; r < s.size(); ++r) {
      if (pat.find(s[r]) != pat.end()) {
        mod[s[r]]++;
      }
      while (l <= r && check()) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          st = l;
        }
        if (pat.find(s[l]) != pat.end()) mod[s[l]]--;
        ++l;
      }
    }
    return st == -1 ? "" : s.substr(st, len);
  }
};


// int main() {
//   Solution sol;
//   assert(sol.minWindow("ADOBECODEBANC", "ABC") == "BANC");
// }