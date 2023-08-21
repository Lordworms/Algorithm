#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
void solve() {
  int n;
  cin >> n;
  vector<ll> cnt(MAXN), a(n + 1), z(n + 1);
  ll maxn = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll x; cin >> a[i];
    z[i] = __builtin_ctzll(a[i]);
    cnt[z[i]]++;
    if (cnt[z[i]] > maxn) {
      maxn = cnt[z[i]];
      ans = z[i];
    }
  } 
  cout << n - maxn << '\n';
  for (int i = 1; i <= n; ++i) {
    if (z[i] != ans) {
      cout << a[i] << ' ';
    }
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