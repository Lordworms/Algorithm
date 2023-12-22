#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
struct Fig {
  int k, c;
};
void solve() {
  int n, t;
  cin >> n;
  vector<Fig> a(n + 1);
  for (int i = 1; i <= n; ++i) {
   cin >> a[i].k >> a[i].c;
  }
  sort(a.begin() + 1, a.end(), [&] (Fig a, Fig b) {
    return a.c < b.c;
  });
  cin >> t;
  vector<int> p(t + 2);
  for (int i = 1; i <= t; ++i) cin >> p[i];
  for (int i = t; i > 1; --i) {
    p[i] -= p[i - 1];
  }
  p[t + 1] = INF;
  int cur = 1;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    while (a[i].k > p[cur]) {
      ans += 1ll * cur * a[i].c * p[cur];
      a[i].k -= p[cur];
      ++cur;
    }  
    ans += 1ll * a[i].k * a[i].c * cur;
    p[cur] -= a[i].k;
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