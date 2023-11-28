#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> dfn(n + 1), ans(10 * n + 10);
  int cnt = 0;
  vector<vector<int>> E(n + 1);
  bool flag = false;
  int st = -1, ed = -1;
  function<void(int)> dfs = [&](int x) {
    if (flag) return;
    ++cnt;
    ans[cnt] = x;
    dfn[x] = cnt;
    for (int &v : E[x]) {
      if (dfn[v] && dfn[x] - dfn[v] >= k) {
        flag = 1;
        st = x;
        ed = v;
      } else if (!dfn[v]) {
        dfs(v);
      }
    }
  };
  int u, v;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1);
  cout << dfn[st] - dfn[ed] + 1 << '\n';
  for (int i = dfn[ed]; i <= dfn[st]; ++i) {
    cout << ans[i] << " \n" [i == dfn[st]];
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