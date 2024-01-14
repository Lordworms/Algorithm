/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
      int firstcol = false, firstrow = false;
      int n = mat.size(), m = mat[0].size();
      for (int i = 0; i < n; ++i) {
        if (mat[i][0] == 0) {
          firstcol = true;
        }
      }  
      for (int j = 0; j < m; ++j) {
         if (mat[0][j] == 0) {
           firstrow = true;
         }
      }
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
          if (mat[i][j] == 0) {
            mat[i][0] = mat[0][j] = 0;
          }
        }
      }
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
          if (mat[i][0] == 0 || mat[0][j] == 0) {
            mat[i][j] = 0;
          }
        }
      }
      if (firstcol) {
        for (int i = 0; i < n; ++i) {
          mat[i][0] = 0;
        }
      }
      if (firstrow) {
        for (int j = 0; j < m; ++j) {
          mat[0][j] = 0;
        }
      }
    }
};
// @lc code=end
// int main() {
//   Solution sol;
// //   vector<vector<int>> a = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//   vector<vector<int>> a = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//   sol.setZeroes(a);
//   return 0;
// }
