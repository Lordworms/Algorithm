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
      int n = mat.size(), m = mat[0].size();
      bool zero_col0 = false, zero_row0 = false;
      for (int i = 0; i < n; ++i) {
        if (!mat[i][0]) {
          zero_col0 = true;  
        }
      }      
      for (int i = 0; i < m; ++i) {
        if (!mat[0][i]) {
          zero_row0 = true;
        }
      }
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
          if (!mat[i][j]) {
            mat[i][0] = mat[0][j] = 0;
          }    
        }
      }
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
          if (!mat[i][0] || !mat[0][j]) {
            mat[i][j] = 0;
          }  
        }
      }
      if (zero_col0) {
        for (int i = 0; i < n; ++i) {
          mat[i][0] = 0;
        }
      }
      if (zero_row0) {
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
//   vector<vector<int>> a = {{1, 0, 3}};
//   sol.setZeroes(a);
//   return 0;
// }
