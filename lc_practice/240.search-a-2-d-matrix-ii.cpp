/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
      int n = mat.size(), m = mat[0].size();
      int l = 0, r = m - 1;
      while (l < n && r >= 0) {
        if (mat[l][r] == target) return true;
        if (mat[l][r] < target) {
          ++l;
        } else {
          --r;
        }
      }
      return false;
    }
};
// @lc code=end
