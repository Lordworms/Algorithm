/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution { 
public:
    bool exist(vector<vector<char>>& g, string word) {
      int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      bool valid = false;
      vector<vector<int>> vis(g.size(), vector<int>(g[0].size()));
      int n = g.size(), m = g[0].size();
      function<void(string, int, int)> dfs = [&](string cur, int x, int y) {
        cur += g[x][y];
        if (cur == word) {
          valid = true;
          return;
        }      
        char nxt = word[cur.size()];
        for (int i = 0; i < 4; ++i) {
          int new_x = x + dir[i][0], new_y = y + dir[i][1];
          if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && g[new_x][new_y] == nxt && !vis[new_x][new_y]) {
            vis[new_x][new_y] = 1;
            dfs(cur, new_x, new_y);
            vis[new_x][new_y] = 0;
          }
        }
      }; 
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (g[i][j] == word[0]) {
            vis[i][j] = 1;
            dfs("", i, j);
            vis[i][j] = 0;
          }
        }
      }
      return valid;
    }
};
// @lc code=end
int main() {
  Solution sol;
  vector<vector<char>> mp = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  assert(sol.exist(mp, "ABCCED") == true);
}

