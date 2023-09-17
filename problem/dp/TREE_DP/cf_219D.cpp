#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n + 1), cost(E);
  vector<int> dp(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
    cost[u].push_back(0);
    cost[v].push_back(1);
  } 
  function<void(int, int)> dfs1 = [&](int x, int f) {
    for (int i = 0; i < E[x].size(); ++i) {
      int v = E[x][i], c = cost[x][i];
      if (v == f) continue;
      dfs1(v, x);
      dp[x] += dp[v] + c;
    }
  };
  dfs1(1, 0);
  int ans = INT_MAX;
  function<void(int, int)> dfs2 = [&](int x, int f) {
    for (int i = 0; i < E[x].size(); ++i) {
      int v = E[x][i], c = cost[x][i];
      if (v == f) continue;
      dp[v] = dp[x] + (c ? -1 : 1);
      dfs2(v, x);
      ans = min(ans, dp[v]);
      ans = min(ans, dp[x]);
    }
  };
  dfs2(1, 0);
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i) {
    if (dp[i] == ans) {
      cout << i << ' ';
    }
  }
  return ;
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