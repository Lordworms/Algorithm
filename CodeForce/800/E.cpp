#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
using pii = pair<ll, int>;
void solve() {
  priority_queue<pii, vector<pii>, greater<pii>> q;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n + 1);
  vector<int> deg(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    E[y].push_back(x);
    ++deg[x];
  }
  q.push({0, n});
  vector<int> vis(n + 1);
  vector<ll> dis(n + 1, (ll)MOD);
  dis[n] = 0;
  while (!q.empty()) {
    auto [d, now] = q.top();
    q.pop();
    if (vis[now]) continue;
    vis[now] = 1;
    for (int v : E[now]) {
      if (d + deg[v] < dis[v]) {
        dis[v] = d + deg[v];
        q.push({dis[v], v});
      }
      --deg[v];
    }
  }
  cout << dis[1] << '\n';
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