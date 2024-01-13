#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
struct Item {
  int c, t;
};
const int INF = 0x3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector<Item> a(n + 1);
  int m = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].t >> a[i].c;
    ++a[i].t;
    m = max(m, a[i].t);
  }
  m += n;
  vector<int> dp(m + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= a[i].t; --j) {
      dp[j] = min(dp[j], dp[j - a[i].t] + a[i].c);
    }
  }
  int ans = INT_MAX;
  for (int i = n; i <= m; ++i) {
    ans = min(ans, dp[i]);  
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