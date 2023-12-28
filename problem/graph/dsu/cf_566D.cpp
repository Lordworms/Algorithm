/*
    using the easist way to union and merge, we could use that
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 2e5 + 100;
struct Dsu {
  int f[MAXN];
  Dsu(int n) {
    iota(f, f + n + 1, 0);
  }
  int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]); // should update it concurrently
  }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    f[y] = x;
  }
  bool judge(int x, int y) {
    return find(x) == find(y);
  }
};
void solve() {
  int n, q, type, x, y;
  cin >> n >> q;
  Dsu dsu(n);
  vector<int> cur_end(n + 2);
  for (int i = 1; i <= n; ++i) cur_end[i] = i;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      dsu.merge(y, x);
    } else if (type == 2) {
      cur_end[x] = cur_end[y];
      int tmp;
      for (int i = x; i < y; i = tmp) {
        dsu.merge(i, i + 1);
        tmp = cur_end[i + 1];
        cur_end[i + 1] = cur_end[y]; // important since we should set the next should updated value to be tmp
      }
    } else {
      cout << (dsu.judge(x, y) ? "YES" : "NO") << '\n';
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