/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string reverseWords(string s) {
    string tmp;
    int n = s.size();
    int l = 0, r = 0;
    while (r < n) {
      while (r < n && s[r] != ' ') ++r;
      reverse(s.begin() + l, s.begin() + r);
      l = r;
      while (s[r] == ' ') ++r;
      l = r;
    }
    reverse(s.begin(), s.end());
    // delete space
    int l1 = 0, l2 = 0;
    bool is_first = true;
    while (l1 < n && l2 < n) {
      while (s[l2] == ' ') {
        ++l2;
      }
      if (is_first) {
        is_first = false;
      } else if (!is_first) {
        s[l1++] = ' ';
      }
      while (l2 < n && s[l2] != ' ') {
        s[l1++] = s[l2++];
      }
    }
    s = s.substr(0, l1);
    if (s.back() == ' ') s.pop_back();
    return s;
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.reverseWords("a good   example");
//   return 0;
// }
