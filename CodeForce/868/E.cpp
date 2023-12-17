#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<vector<int>> E(n + 1);
  vector<int> vis(n + 1);
  int u, v;
  for (int i = 1; i <= n; ++i) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  int ans = 0, len = 0;
  function<void(int)> dfs = [&](int x) {
    vis[x] = 1;
    len++;
    for (auto &v : E[x]) {
      if (!vis[v]) {
        dfs(v);
      }
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      len = 0;
      dfs(i);
      if (len <= l + r - 1) {
        ans ^= len / l;
      }
    }
  }
  if (ans) {
    cout << "Alice" << '\n';
  } else {
    cout << "Bob" << '\n';
  }
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