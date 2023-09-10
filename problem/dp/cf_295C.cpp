#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 55;
#define total(x, y) ((x * 50 + y * 100))
ll A[N][N][N][N];
ll C[N][N];
ll dp[N << 2][N][N];
void solve() {
  ll n, lim;
  cin >> n >> lim;
  vector<int> a(n + 1);
  int cnta = 0, cntb = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 50) {
      cnta++;
    } else {
      cntb++;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = C[i][0] = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  for (int a = 0; a < N; ++a) {
    for (int b = 0; b < N; ++b) {
      for (int c = 0; c <= a; ++c) {
        for (int d = 0; d <= b; ++d) {
          A[a][b][c][d] = (C[a][c] * C[b][d]) % MOD;
        }
      }
    }
  }
  dp[0][cnta][cntb] = 1;
  for (int i = 1; i <= 4 * n + 1; i += 2) {
    ll res = 0;
    // positive direction
    for (int x = 0; x <= cnta; ++x) {
      for (int y = 0; y <= cntb; ++y) {
        if (dp[i - 1][x][y]) {
          for (int a = 0; a <= x; ++a) {
            for (int b = 0; b <= y; ++b) {
              if ((a | b) && (total(a, b) <= lim)) {
                dp[i][x - a][y - b] +=
                    (A[x][y][a][b] * dp[i - 1][x][y]);
                dp[i][x - a][y - b] %= MOD;
              }
            }
          }
        }
      }
    }
    if (dp[i][0][0]) {
      cout << i << '\n' << dp[i][0][0] << '\n';
      return;
    }
    // negative direction
    for (int x = 0; x <= cnta; ++x) {
      for (int y = 0; y <= cntb; ++y) {
        if (dp[i][x][y]) {
          for (int a = 0; a <= cnta - x; ++a) {
            for (int b = 0; b <= cntb - y; ++b) {
              if ((a | b) && (total(a, b) <= lim)) {
                dp[i + 1][x + a][y + b] +=
                    (A[cnta - x][cntb - y][a][b] * dp[i][x][y]);
                dp[i + 1][x + a][y + b] %= MOD;
              }
            }
          }
        }
      }
    }
  }
  cout << -1 << '\n' <<0 <<'\n';
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