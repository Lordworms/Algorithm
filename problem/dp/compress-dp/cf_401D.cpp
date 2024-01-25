#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
#define int ll
const int N = 18;
int a[N];
int dp[1 << N][111];
void solve() {
  ll n, m, c = 1;
  cin >> n >> m;
  map<ll, ll> cnt;
  int len = 0;
  while (n) {
    a[len++] = n % 10;
    cnt[n % 10]++;
    c *= cnt[n % 10];
    n /= 10;
  }
  dp[0][0] = 1;
  for (ll i = 0; i < (1 << len); ++i) {
    for (ll j = 0; j < len; ++j) {
      ll bit = i & (1 << j), pre = i || a[j];
      if (bit == 0 && pre) {
        for (ll k = 0; k < m; ++k) {
          dp[i | (1 << j)][(k * 10 + a[j]) % m] += dp[i][k];
        }
      } 
    }
  }
  cout << dp[(1 << len) - 1][0] / c << '\n';
  return;
}
signed main() {
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