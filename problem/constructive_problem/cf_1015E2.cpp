#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector mp(n + 1, vector<int>(m + 1)), mark(mp), sz(mp);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      mp[i][j] = (c == '*');
    }
  }
  auto check = [&](int x, int y, int k) {
    return (x - k) && (x + k) <= n && (y - k) && (y + k) <= m && mp[x + k][y] &&
           mp[x - k][y] && mp[x][y + k] && mp[x][y - k];
  };
  int ans = 0;
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      if (!mp[i][j] || !mp[i - 1][j] || !mp[i][j - 1] || !mp[i][j + 1] ||
          !mp[i + 1][j]) {  // do not do non-center point again
        continue;
      }
      mark[i][j] = 1;
      int len = 1;
      for (; check(i, j, len); len++) {
        mark[i - len][j] = mark[i + len][j] = mark[i][j + len] =
            mark[i][j - len] = 1;
      }
      sz[i][j] = len - 1;
      ++ans;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mp[i][j] && !mark[i][j]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (sz[i][j]) {
        cout << i << ' ' << j << ' ' << sz[i][j] << '\n';
      }
    }
  }
  return 0;
}