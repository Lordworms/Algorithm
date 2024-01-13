/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
      string mod = "$";
      for (auto c : s) {
        mod += '#';
        mod += c;
      }
      mod += '#';
      int n = mod.size();
      vector<int> P(n + 1);
      int mid = 0, st = -1, len = INT_MIN, R = 0;
      for (int i = 1; i < n; ++i) {
        P[i] = R > i ? min(P[2 * mid - i], R - i) : 0;
        while (i - P[i] - 1 >= 0 && mod[P[i] + 1 +i] == mod[i - P[i] - 1]) ++P[i];
        if (i + P[i] > R) {
          R = i + P[i];
          mid = i;
        }
        if (P[i] > len) {
          len = P[i];
          st = (i - P[i]) >> 1;
        }
      }
      return st == -1 ? "" : s.substr(st, len);
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   assert(sol.longestPalindrome("babad") == "bab");
// }
