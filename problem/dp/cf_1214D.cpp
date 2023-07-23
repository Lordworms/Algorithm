#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int dir[2][2] = {{0, 1}, {1, 0}};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> mp(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mp[i][j];
    }
  }
  int ans = 0;
  function<bool(int, int)> check = [&](int x, int y) {
    return x <= n && x >= 1 && y <= m && y >= 1;
  };
  function<void(int, int)> dfs = [&](int x, int y) {
    if (ans) {
      return;
    }
    if (x == n && y == m) {
      ans = 1;
      return;
    }
    for (int i = 0; i < 2; ++i) {
      int tx = x + dir[i][0], ty = y + dir[i][1];
      if (!check(tx, ty)) {
        continue;
      }
      if (mp[tx][ty] == '#') {
        continue;
      }
      mp[tx][ty] = '#';
      dfs(tx, ty);
      if (ans) return;
    }
  };
  mp[1][1] = '#';
  dfs(1, 1);
  if (!ans) {
    cout << 0 << '\n';
  } else {
    ans = 0;
    swap(dir[0], dir[1]);
    mp[n][m] = '.';
    dfs(1, 1);
    ans++;
    cout << ans << '\n';
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}