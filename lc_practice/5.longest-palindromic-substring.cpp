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
      /*
        make the total length an even number
      */
      string mod = "%";
      for (auto c : s) {
        mod += '#';  
        mod += c;
      }
      mod += '#';
      int n = mod.size();
      vector<int> P(n + 1);
      int maxlen = INT_MIN, st = -1, R = 0, mid = 0;
      for (int i = 1; i < n; ++i) {
        // the maxR > i we have to pick up the minimum between the middle and  R - i
        P[i] = R > i ? (P[2 * mid - i], R - i) : 0;
        while (i - P[i] - 1 >= 0 && mod[i - P[i] - 1] == mod[i + P[i] + 1]) ++P[i];
        if (i + P[i] > R) {
          R = i + P[i];
          mid = i;
        }
        if (P[i] > maxlen) {
          maxlen = P[i];
          st = (i - P[i]) >> 1;
        }
      }
      if (st == -1) return "";
      return s.substr(st, maxlen);
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   assert(sol.longestPalindrome("babad") == "bab");
// }
