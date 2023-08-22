/**
 * could be in the same set <=> could reach the same end sets
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct node {
  int id;
  basic_string<int> s;
  friend bool operator < (node a, node b) {
    return a.s < b.s;
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> fa(n + 1);
  vector<node> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].id = i;
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    a[u].s += v;
    a[v].s += u;
  }
  for (int i = 1; i <= n; ++i) {
    sort(a[i].s.begin(), a[i].s.end());
  }
  sort(a.begin() + 1, a.end());
  if (!a[1].s.length()) {
    cout << -1 << '\n';
    return;
  }
  int cnt = 1;
  fa[a[1].id] = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i].s == a[i - 1].s) {
      fa[a[i].id] = fa[a[i - 1].id];
    } else {
      fa[a[i].id] = ++cnt;
    }
  }
  if (cnt != 3) {
    cout << -1 << '\n';
  } else {
    for (int i = 1; i <= n; ++i) {
      cout << fa[i] << " \n"[i == n];
    }
  }
  return;
}
int main() {
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