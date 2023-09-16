#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 110;
#define int ll
// d[l][r][k] means we eliminate the same chars in [l,r] and the same k chars which is the same as s[r]
int dp[N][N][N];
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = ')' + s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  } 
  // always do range shit like what describe below
  for (int len = 1; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      for (int k = 0; k + len <= n; ++k) {
        dp[l][r][k] = dp[l][r - 1][0] + a[k + 1];
        for (int mid = l; mid < r; ++mid) {
          if (s[mid] != s[r]) continue;
          // we have two ways to drop shits:
          // first, we could do as what describe above
          // second, we could |||<- mid ||| separate them into two ranges and connected the two ranges with mid
          dp[l][r][k] = max(dp[l][r][k], dp[mid + 1][r - 1][0] + dp[l][mid][k + 1]);
        }     
      }    
    }
  }
  cout << dp[1][n][0] << '\n';
  return ;
}
signed main() {
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