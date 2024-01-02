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
      int m = mat.size(), n = mat[0].size();
      int x = 0, y = n - 1;
      while (x < m && y >= 0) {
        if (mat[x][y] == target) return true;
        if (mat[x][y] < target) {
          ++x;
        } else {
          --y;
        }
      }    
      return false;
    }
};
// @lc code=end
