/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
      int n = mat.size(), m = mat[0].size();
      for (int i = 0; i < n >> 1; ++i) {
        for (int j = 0; j < (n + 1) >> 1; ++j) {
          int tmp = mat[i][j];
          mat[i][j] = mat[n - j - 1][i];
          mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
          mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
          mat[j][n - i - 1] = tmp;
        }
      }
    }
};
// @lc code=end
// int main() {
//   vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//   Solution sol;
//   sol.rotate(a);
//   return 0;
// }
