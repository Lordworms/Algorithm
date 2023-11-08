#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 2e5 + 10;
int col[MAXN], group[MAXN];
ll dp[MAXN];
int cnt;
vector<vector<int>> E, newE;
ll D;
void dfs(int u, int c) {
  group[u] = cnt;
  for (int v : E[u]) {
    if (group[v] == -1 && col[v] == c) {
      dfs(v, c);
    }
  } 
}
void cal(int u, int f) {
  for (int v : newE[u]) {
    if (f == v) continue;
    cal(v, u);
    D = max(D, dp[u] + dp[v] + 1);
    dp[u] = max(dp[u], dp[v] + 1);
  } 
}
void solve() {
  int n;
  cin >> n;
  E.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> col[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  memset(group, -1, sizeof(group)); 
  
  for (int i = 1; i <= n; ++i) {
    if (group[i] == -1) {
      ++cnt;
      dfs(i, col[i]);
    }
  }
  newE.resize(cnt + 1);
  for (int i = 1; i <= n; ++i) {
    for (int &v : E[i]) {
      if (col[v] != col[i]) {
        newE[group[i]].push_back(group[v]);
      }
    }
  }
 
  cal(1, -1);
  cout << ((D >> 1) + (D & 1)) << '\n';
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
  while (T--) {
    solve();
  }
  return 0;
}