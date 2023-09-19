#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
int f[MAXN];
int find(int x) { return f[x] == x ? x : find(f[f[x]]); }
void merge(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) return;
  f[fy] = fx;
}
void solve() {
  int n, m, W;
  cin >> n >> m >> W;
  iota(f + 1, f + n + 1, 1);
  vector<int> w(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    f[find(u)] = find(v);
  }
  vector<ll> dp(W + 1);
  vector<vector<int>> groups(n + 1);
  for (int i = 1; i <= n; ++i) {
    groups[find(i)].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int V = W; V >= 0; --V) {
      int tw = 0, tb = 0;
      for (auto& v : groups[i]) {
        tw += w[v];
        tb += b[v];
        if (V >= w[v]) {
          dp[V] = max(dp[V], dp[V - w[v]] + b[v]);
        }
      }
      if (V >= tw) {
        dp[V] = max(dp[V - tw] + tb, dp[V]);
      }  
    }
  }
  cout << dp[W] << '\n';
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