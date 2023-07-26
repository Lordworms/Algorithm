#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), first(n + 1), last(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (!first[a[i]]) {
      first[a[i]] = i;
    }
    last[a[i]] = i;
  }
  sort(a.begin() + 1, a.end());
  vector<int> dp(n + 1);
  int ans = 0;
  int cnt = unique(a.begin() + 1, a.end()) - a.begin() - 1;
  for (int i = 1; i <= cnt; ++i) {
    if (first[a[i]] > last[a[i - 1]]) {
      dp[a[i]] = dp[a[i - 1]] + 1;
    } else {
      dp[a[i]] = 1;
    }
    ans = max(ans, dp[a[i]]);
  }
  cout << cnt - ans << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}