/*
   we could let dp[i][j][k] be the number of factor 2 when iterating the first
   i element, picking up j element and the number of prime 5 is k
   
   the trans look simple, which is 
   dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][k - fac5[i]] + fac2[i])
   we could change the iterate order to make the first dimension dissapper
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 10020;
const int INF = 0x3f3f3f3f;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  vector<int> fac2(n + 1), fac5(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ll &x = a[i];
    while (x % 5 == 0) {
      x /= 5;
      fac5[i]++;
    }
    while (x % 2 == 0) {
      x /= 2;
      fac2[i]++;
    }
  }
  vector<vector<ll>> dp(
      n + 1, vector<ll>(N, -INF));  // dp[i][j] indicate pick up i number and
                                     // the sum of number of 5 is j
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = k; j >= 1; --j) {
      for (int l = N - 1; l >= fac5[i]; --l) {
        if (a[i]) {
          dp[j][l] = max(dp[j][l], dp[j - 1][l - fac5[i]] + fac2[i]);
        }
      }
    }
  }
  ll ans = 0;
  for (int i = N - 1; i >= 0; --i) {
    ans = max(ans, min((ll)i, dp[k][i])); // total number would be more than i
  }
  cout << ans << '\n';
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