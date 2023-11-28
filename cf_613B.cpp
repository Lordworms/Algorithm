#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
struct skill {
  int lev, id;
};
void solve() {
  int n, A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  vector<skill> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].lev;
    a[i].id = i;
  }
  vector<ll> sum(n + 1);
  sort(a.begin() + 1, a.end(), [&](skill a, skill b) {
    return a.lev < b.lev;
  });
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i].lev;
  }
  for (int i = 1; i <= n; ++i) {
    
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