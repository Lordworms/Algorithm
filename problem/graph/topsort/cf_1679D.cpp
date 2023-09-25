#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
#define int ll
int deg[MAXN];
struct edge {
  int u, v;
};
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n + 1);
  int r = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    r = max(r, a[i]);
  } 
  vector<edge> E;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    E.push_back({u, v});
  }
  function<bool(int)> check = [&] (int mid) {
    for (int i = 1; i <= n; ++i) deg[i] = 0;
    vector<vector<int>> ED(n + 1);
    for (auto& e : E) {
      if (a[e.u] <= mid && a[e.v] <= mid) {
        ED[e.u].push_back(e.v);
        deg[e.v]++;
      }
    }
    queue<int> q;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (!deg[i]) {
        q.push(i);
        dp[i] = 1;
      }
    }
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (int &v : ED[u]) {
        deg[v]--;
        if (!deg[v]) {
          q.push(v);
        }
        dp[v] = max(dp[u] + 1, dp[v]);
      } 
    }
    for (int i = 1; i <= n; ++i) {
      if (deg[i]) {
        return true;
      }
    }
    return *max_element(dp.begin() + 1, dp.end()) >= k;
  };
  int l = 0, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (k == 1) {
    ans = *min_element(a.begin() + 1, a.end());
  }
  cout << ans << '\n';
  return ;
}
signed main() {
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