#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int fa(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return fa(x) == fa(y); }
    bool merge(int x, int y) {
        x = fa(x);
        y = fa(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[fa(x)]; }
};
void solve() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    dsu.merge(u, v);
  }
  vector<vector<int>> group(n + 1);
  for (int i = 1; i <= n; ++i) {
    group[dsu.f[i]].push_back(i);
  }
  vector<vector<int>> ans;
  vector<vector<int>> one_set, two_set;
  for (int i = 1; i <= n; ++i) {
    if (group[i].size() == 3) {
      ans.push_back(group[i]);
    } else if(group[i].size() == 2) {
      two_set.push_back(group[i]);
    } else if (group[i].size() == 1) {
      one_set.push_back(group[i]);
    } else if (group[i].size() > 3) {
      cout << -1 << '\n';
      return;
    }
  }
  while (!one_set.empty() && !two_set.empty()) {
    one_set.front().insert(one_set.front().begin(), two_set.front().begin(), two_set.front().end());
    two_set.erase(two_set.begin());
    ans.push_back(one_set.front()); // front gives a reference
    one_set.erase(one_set.begin());
  }
  if (two_set.size() > 0) {
    cout << -1 << '\n';
    return;
  }
  while (one_set.size() >= 3) {
    int a, b, c;
    auto f = one_set.begin();
    a = f->front(), f = one_set.erase(f);
    b = f->front(), f = one_set.erase(f);
    c = f->front(), f = one_set.erase(f);
    ans.push_back({a, b, c});
  }
  if (one_set.size()) {
    cout << -1 << '\n';
    return;
  }
  for (auto &v : ans) {
    for (auto &e : v) {
      cout << e << ' ';
    }
    cout << '\n';
  }
  return ;
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