/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool checkValidString(string s) {
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '*' || s[i] == '(') {
        ++left;
      } else {
        ++right;
      }
      if (right > left) {
        return false;
      }
    }
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '*' || s[i] == ')') {
        ++left;
      } else {
        ++right;
      }
      if (right > left) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
