#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
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
  int n;
  cin >> n;
  DSU dsu(n + 1);
  vector<int> a(n + 1), b(a),match(a);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    dsu.merge(a[i], b[i]);
  }
  map<int, int> groups;
  for (int i = 1; i <= n; ++i) {
    groups[dsu.fa(i)]++;
  }
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + i;
  }
  ll l = 1, r = n;
  ll ans = 0;
  for (auto &k : groups) {
    int cnt = k.second;
    if (cnt == 1) continue;
    ll l1 = l + cnt / 2 - 1, r1 = r - cnt / 2 + 1; // the only one left should not do
    ans += 2 * ((p[r] - p[r1 - 1]) - (p[l1] - p[l - 1]));
    l = l1 + 1;
    r = r1 - 1;
  }
  cout << ans << '\n';
}  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}