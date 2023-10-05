#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), deg(n + 1), tmp(n + 1);
  vector<ll> dp(n + 1);
  vector<vector<int>> E(n + 1);
  function<bool()> check = [&] () {
    for (int i = 1; i <= n; ++i) {
      if (a[i] > 0) {
        return false;
      }
    }
    return true;
  };
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    deg[v]++;
  }
  // case 1: if could check then return true
  if (check()) {
    cout << 0 << '\n';
    return;
  }
  for (int t = 1; t <= n; ++t) {
    for (int u = 1; u <= n; ++u) {
      tmp[u] = a[u]; 
    }
    for (int u = 1; u <= n; ++u) {
      if (a[u] == 0) {
        continue;
      }    
      tmp[u]--;
      for (int v : E[u]) {
        tmp[v]++;
      }
    }
    for (int u = 1; u <= n; ++u) {
      a[u] = tmp[u];
    }
    if (check()) {
      cout << t << '\n';
      return;
    }
  }
  deque<int> q;
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) {
      q.push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = a[i];
  }
  int u;
  while (!q.empty()) {
    u = q.front();
    q.pop_front();
    for (int v : E[u]) {
      deg[v]--;
      if (!deg[v]) {
        q.push_back(v);
      }
      dp[v] = (dp[v] + dp[u]) % MOD; 
    }
  }
  cout << (dp[u] + n) % MOD << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt", "r", stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}