#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
using pii = pair<int, int>;
void solve() {
  int n, k, d;
  cin >> n >> k >> d;
  vector<vector<pii>> E(n + 1);
  vector<int> police(k + 1);
  queue<pii> q;
  for (int i = 1; i <= k; ++i) {
    cin >> police[i];
    q.push({police[i], 0});
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back({v, i});
    E[v].push_back({u, i});
  }
  vector<int> vis(n + 1, 0), line_mark(n, 0);
  while (!q.empty()) {
    auto cur = q.front().first;
    auto from = q.front().second;
    q.pop();
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (auto &p : E[cur]) {
      if (p.first == from) continue;
      if (vis[p.first]) {
        line_mark[p.second] = 1;
      } else {
        q.push({p.first, cur});
      }
    }
  }
  int cnt = accumulate(line_mark.begin(), line_mark.end(), 0);
  cout << cnt << '\n';
  for (int i = 1; i < n; ++i) {
    if (line_mark[i]) {
      cout << i << ' ';
    }
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