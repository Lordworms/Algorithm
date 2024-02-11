/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
class Solution {
 public:
  int flipLights(int n, int p) {
    if (p == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) {
        if (p == 1) return 3;
        else return 4;
    }
    if (p > 2) return 8;
    else return p == 1? 4 : 7;
  }
};
// @lc code=end
