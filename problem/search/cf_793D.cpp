#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
using pii = pair<int, int>;
const int N = 81;
int dp[N][N][N][N];
int n, k, m;
vector<vector<pii>> E;
int dfs(int x, int y, int cur, int cnt) {
  if (cnt == k) return 0;
  if (dp[x][y][cur][cnt]) {
    return dp[x][y][cur][cnt];
  }
  int &res = dp[x][y][cur][cnt];
  res = 1e9;
  for (auto &p : E[cur]) {
    auto &v = p.first;
    auto &c = p.second;
    if (v > x && v < y && v != cur) {
      if (cur > p.first) {
        res = min(res, c + dfs(x, cur, v, cnt + 1));
      } else {
        res = min(res, c + dfs(cur, y, v, cnt + 1));
      }     
    }
  } 
  return res; 
}
void solve() {
  cin >> n >> k >> m;
  E.resize(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    E[u].push_back({v, c});
  }
  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, dfs(0, n + 1, i, 1));
  }
  if (ans == 1e9) ans = -1;
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