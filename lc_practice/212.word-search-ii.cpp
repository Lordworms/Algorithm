/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int N = 3e4 + 10;
    int n = board.size(), m = board[0].size();
    vector<vector<int>> tr(N << 2, vector<int>(26));
    vector<int> count(N << 2);
    map<int, string> mp;
    int cnt = 0;
    function<void(string)> add = [&](string s) {
      int u = 0;
      for (int i = 0; i < s.size(); ++i) {
        // count[u]++;
        int id = s[i] - 'a';
        if (!tr[u][id]) {
          tr[u][id] = ++cnt;
        }
        u = tr[u][id];
      }
      mp[u] = s;
    };
    // function<void(string)> remove = [&](string s) {
    //   int u = 0;
    //   for (int i = 0; i < s.size(); ++i) {
    //     --count[u];
    //     int id = s[i] - 'a';
    //     if (count[u] == 0) {
    //       tr[u][id] = 0;
    //       break;
    //     }
    //     u = tr[u][id];
    //   }
    // };
    for (auto s : words) {
      add(s);
    }
    vector<vector<int>> vis(n, vector<int>(m));
    set<string> res;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    function<void(int, int, int)> dfs = [&](int x, int y, int u) {
      int id = board[x][y] - 'a';
      u = tr[u][id];
      if (u == 0) return;
      if (mp.count(u)) {
        res.insert(mp[u]);
        // if (--count[u] == 0) {
        //   remove(mp[u]);
        // }
        mp.erase(u);
      }
      vis[x][y] = 1;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
            tr[u][board[nx][ny] - 'a']) {
          int new_id = board[nx][ny] - 'a';
          dfs(nx, ny, u);
        }
      }
      vis[x][y] = 0;
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (tr[0][board[i][j] - 'a']) {
          dfs(i, j, 0);
        }
      }
    }
    vector<string> ans(res.begin(), res.end());
    return ans;
  }
};
// @lc code=end
// int main() {
//   vector<vector<char>> g = {{'o', 'a', 'a', 'n'},
//                             {'e', 't', 'a', 'e'},
//                             {'i', 'h', 'j', 'r'},
//                             {'i', 'f', 'l', 'v'}};
//   vector<string> s = {"eat", "oath"};
//   //   vector<vector<char>> g = {{'a'}};
//   //   vector<string> s = {"a"};
// //   vector<vector<char>> g = {{'a', 'a', 'a', 'b'}, {'b', 'b', 'a', 'b'}};
// //   vector<string> s = {"bbabb"};
//   Solution sol;
//   sol.findWords(g, s);
// }