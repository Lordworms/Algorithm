/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
      int n = g.size(), m = g[0].size();
      vector<vector<int>> vis(n, vector<int>(m));
      auto check = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && g[i][j] == '1';
      };
      vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      function<void(int, int)> dfs = [&](int x, int y) {
        g[x][y] = '0';
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
          int new_x = x + dir[i][0], new_y = y + dir[i][1];
          if (check(new_x, new_y)) {
            dfs(new_x, new_y);    
          }
        }
      };
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (g[i][j] == '1') {
            dfs(i, j);
            ++ans;  
          }
        }
      }
      return ans;
    }
};
// @lc code=end

