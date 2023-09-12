#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f;
void solve() {
  int n, m, T;
  cin >> n >> m >> T;
  vector<vector<int>> E(n + 1), cost(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF)), pre(dp);
  vector<int> in(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    E[u].push_back(v);
    cost[u].push_back(t);
    in[v]++;
  }
  queue<int> q;
  for (int v = 1; v <= n; ++v) {
    if (!in[v]) {
      q.push(v);
    }
  }
  pre[1][1] = -1;
  dp[1][1] = 0;
  // dp[i][j] means the answer when passes j points and the current point is i
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int i = 0; i < E[u].size(); ++i) {
      int v = E[u][i], c = cost[u][i];
      --in[v];
      if (!in[v]) {
        q.push(v);
      }
      for (int t = 2; t <= n; ++t) {
        if (dp[v][t] > dp[u][t - 1] + c) {
          dp[v][t] = dp[u][t - 1] + c;
          pre[v][t] = u;
        }
      }
    }
  }
  function<void(int, int)> print_trace = [&] (int cur, int t) {
    if (pre[cur][t] == -1) {
      cout << cur << ' ';
      return;
    }  
    print_trace(pre[cur][t], t - 1);
    cout << cur << ' ';
  };
  // reverse iteration
  for (int i = n; i >= 1; --i) {
    if (dp[n][i] <= T) {
      cout << i << '\n';
      print_trace(n, i);
      break;
    }
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