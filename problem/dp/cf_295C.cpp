#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 105;
const int MAXP = 15;
ll dp[MAXN][MAXN][MAXP];
void solve() {
  int n, m, p;
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> p;
  ++p;
  vector<vector<int>> mp(n, vector<int>(m));
  char c;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      mp[i][j] = c - '0';
    }
  }
  for (int j = 0; j < m; ++j) {
    dp[n - 1][j][mp[n - 1][j] % p] = mp[n - 1][j];
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < p; ++k) {
        int y = (k - mp[i][j] % p + p) % p;
        if (j > 0 && dp[i + 1][j - 1][y] != -1) {
          dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - 1][y] + mp[i][j]);
        }
        if (j < m - 1 && dp[i + 1][j + 1][y] != -1) {
          dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j + 1][y] + mp[i][j]);
        }
      }
    }
  }
  int pos = 0;
  for (int i = 1; i < m; ++i) {
    if (dp[0][i][0] > dp[0][pos][0]) {
      pos = i;
    }
  }
  if (dp[0][pos][0] == -1) {
    cout << -1 << '\n';
    return;
  }
  cout << dp[0][pos][0] << '\n';
  stack<char> st;
  int x = 0, y = 0, j = pos;
  for (int i = 0; i < n - 1; ++i) {
    y = (x - mp[i][j] % p + p) % p;
    if (j == 0 || dp[i][j][x] == dp[i + 1][j + 1][y] + mp[i][j]) {
      st.push('L');
      ++j;
    } else {
      st.push('R');
      --j;
    }
    x = y;
  }
  cout << j + 1 << '\n';
  while (!st.empty()) {
    cout << st.top();
    st.pop();
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