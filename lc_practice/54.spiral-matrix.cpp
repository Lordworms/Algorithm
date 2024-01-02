/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> ans;
    int m = mat.size(), n = mat[0].size(), up = 1, down = m - 1, left = 0,
        right = n - 1, x = 0, y = 0, dirx = 0, diry = 1;
    for (int i = 0; i < m * n; ++i) {
      if (i == m * n - 2) {
        int k = 1;
      }
      ans.push_back(mat[x][y]);
      if (diry != 0) {
        if (diry == 1 && y == right) {
          diry = 0;
          --right;
          dirx = 1;
        } else if (diry == -1 && y == left){
          diry = 0;
          ++left;
          dirx = -1;
        }
      }
      if (dirx != 0) {
        if (dirx == 1 && x == down) {
          dirx = 0;
          --down;
          diry = -1;
        } else if (dirx == -1 && x == up){
          dirx = 0;
          ++up;
          diry = 1;
        }
      }
      if (dirx != 0) {
        x += dirx;
      } else {
        y += diry;
      }
    }
    return ans;
  }
};
// @lc code=end
// int main() {
//   vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//   Solution sol;
//   sol.spiralOrder(a);
// }
