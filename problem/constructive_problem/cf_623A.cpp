#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 100;
int mp[N][N];
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n + 1);
  int u, v;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    mp[u][v] = mp[u][u] = 1;
  }
  vector<int> col(n + 1, -1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (!mp[i][j]) {
        E[i].push_back(j);
      }
    }
  }
  function<int(int)> dfs = [&] (int x) {
    for (int &v : E[x]) {
      if (col[v] == col[x]) {
        return 0;
      }
      if (col[v] != -1) {
        continue;
      }
      col[v] = col[x] ^ 1;
      if (!dfs(v)) return 0;
    }
    return 1;
  };
  for (int i = 1; i <= n; ++i) {
    if (E[i].size() == 0) continue;
    col[i] = 0;
    if (!dfs(i)) {
      cout << "No" << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      // connected in the previous graph and connected in rem graph
      if (mp[i][j] && col[i] + col[j] == 1) {
        cout << "No" << '\n';
        return;
      }
    }
  } 
  cout << "Yes" << '\n';
  for (int i = 1; i <= n; ++i) {
    if (col[i] == 0) cout << "a";
    else if (col[i] == -1) cout << "b";
    else cout << "c";
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