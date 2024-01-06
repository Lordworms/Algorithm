/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  using pii = pair<int, int>;
  int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    deque<pii> q;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 2) {
          q.push_back({i, j});
        }
        if (grid[i][j] == 1) {
          ++cnt;
        }
      }
    }
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> vis(n, vector<int>(m));
    auto check = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] &&
             grid[x][y] == 1;
    };
    int ans = 0;
    while (!q.empty()) {
      int siz = q.size();
      for (int i = 0; i < siz; ++i) {
        auto p = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
          int x = p.first + dir[i][0];
          int y = p.second + dir[i][1];
          if (check(x, y)) {
            q.push_back({x, y});
            vis[x][y] = 1;
            --cnt;
          }
        }
      }
      if (q.size()) ++ans;
    }
    if (cnt) return -1;
    return ans;
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<vector<int>> a = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
//   assert(sol.orangesRotting(a) == 4);
// }
