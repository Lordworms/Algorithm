#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MMOD = 2 * MOD - 2;
const int N = 2e5 + 7;
ll qpow(ll base, ll exp) {
  ll ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % MOD;
    base = base * base % MOD;
    exp >>= 1;
  }
  return ans;
}
void solve() {
  int m;
  cin >> m;
  vector<int> mp(N);
  vector<int> a(m + 1);
  unordered_set<int> s;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
    mp[a[i]]++;
    s.insert(a[i]);
  }
  ll sum = 1, ans = 1;
  for (auto &e : s) sum = sum * (mp[e] + 1) % MMOD;
  for (auto &e : s) ans = (ans * qpow(1ll * e, sum * mp[e] / 2) % MOD) % MOD;
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