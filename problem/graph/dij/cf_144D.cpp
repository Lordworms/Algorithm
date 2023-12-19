#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
struct Node {
  int id, d;
  bool operator < (const Node &a) const {
    return d > a.d;
  }      
};
struct Edge {
  int from, to, d;  
};
void solve() {
  int n, m, s, u, v, w, l;
  cin >> n >> m >> s;
  vector<vector<int>> E(n + 1), cost(n + 1);
  vector<Edge> edg;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> w;
    edg.push_back({u, v, w});
    E[u].push_back(v);
    E[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);   
  }
  cin >> l;
  vector<int> dis(n + 1, INF), vis(n + 1);
  priority_queue<Node> q;
  q.push({s, 0});
  dis[s] = 0;
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    vis[p.id] = 1;
    for (int i = 0; i < E[p.id].size(); ++i) {
      int &c = cost[p.id][i];
      int v = E[p.id][i];
      if (vis[v]) continue;
      if (dis[v] > dis[p.id] + c) {
        dis[v] = dis[p.id] + c;
        q.push({v, dis[v]});
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (dis[i] == l) {
      ++ans; 
    }
  }
  for (auto &e : edg) {
    int &v = e.to, &u = e.from, &c = e.d;
    if (dis[v] >= l && dis[u] >= l) continue;
    if (dis[u] >= l && dis[v] < l && dis[v] + c > l) {
      ++ans;
    } 
    if (dis[v] >= l && dis[u] < l && dis[u] + c > l) {
      ++ans;
    }
    if (dis[v] < l && dis[u] < l) {
      if (dis[v] + dis[u] + c == 2 * l) ++ans;
      else if (dis[v] + dis[u] + c > 2 * l) ans += 2;  
    }
   }
  cout << ans << '\n';
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