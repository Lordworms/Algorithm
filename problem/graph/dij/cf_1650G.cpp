#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
struct node {
  int id, dis;
  bool operator < (const node & a) const {
    return dis > a.dis;
  }
};
int dp[MAXN][2];
void solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<int>> E(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  memset(dp, 0, sizeof(dp));
  vector<int> vis(n + 1), dep(n + 1, 0x3f3f3f3f);
  vector<vector<int>> vec(n + 1);
  function<void()> dijstra = [&] () {
    priority_queue<node> q;
    q.push({s, 0});
    dep[s] = 0;
    while (!q.empty()) {
      auto p = q.top();
      q.pop();
      vis[p.id] = 1;
      for (int v : E[p.id]) {
        if (dep[v] > dep[p.id] + 1) {
          dep[v] = dep[p.id] + 1;
          if (!vis[v]) q.push({v, dep[v]});
        }
      }
    }
  };
  dijstra();
  function<void()> bfs = [&] () {
    for (int i = 0; i <= n; ++i) vec[i].clear();
    for (int i = 1; i <= n; ++i) {
      vec[dep[i]].push_back(i);
    }
    dp[s][0] = 1;
    for (int d = 0; d <= n; ++d) {
      for (auto &x : vec[d]) {
        for (int &v : E[x]) {
          if (dep[v] == d) {
            dp[v][1] = (dp[v][1] + dp[x][0]) % MOD;  
          }
        }
      }
      for (auto &x : vec[d]) {
        for (int &v : E[x]) {
          if (dep[v] == d + 1) {
            dp[v][0] = (dp[v][0] + dp[x][0]) % MOD;  
            dp[v][1] = (dp[v][1] + dp[x][1]) % MOD;  
          }
        }
      }
    }
  };
  bfs();
  cout << (dp[t][0] + dp[t][1]) % MOD << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}