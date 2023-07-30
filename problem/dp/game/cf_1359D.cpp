#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector dp (n + 1, vector<int> (61, -INF));
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  } 
  /*
    dp[i][a[i] + 30] = max (dp[i][j], dp[i - 1][j] + j - 30)
  */
  dp[1][a[1] + 30] = 0;
  for (int i = 2; i <= n; ++i) {
    int cur = a[i] + 30;
    dp[i][cur] = 0; //important ! just pick up one shit
    for (int j = 0; j <= cur; ++j) {
      dp[i][cur] = max(dp[i][cur], dp[i - 1][j] + j - 30);
    }
    for (int j = cur + 1; j <= 60; ++j) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 60; ++j) {
      ans = max(ans, dp[i][j]);    
    }
  }
  cout << ans << '\n';
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in","r",stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out","w",stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}