#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, flag = 0;
  cin >> n;
  vector<ll> a(n + 1), ans(n + 1);
  vector<int> vis(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  function<void()> print = [&]() {
    for (int i = 1; i <= n; ++i) {
      cout << ans[i] << " \n" [i == n];
    }
  };
  function<void(int, int)> dfs = [&] (int x, int step) {
    if (step == n && !flag) {
      flag = 1;
      print();
      return;
    }
    vis[x] = 1;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && (a[i] == ans[step] * 2 || ans[step] == a[i] * 3)) {
        ans[step + 1] = a[i];
        dfs(i, step + 1);
      }
    }
    vis[x] = 0;
  };
  for (int i = 1; i <= n; ++i) {
    ans[1] = a[i];
    fill(vis.begin(), vis.end(), 0);
    dfs(i, 1);
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