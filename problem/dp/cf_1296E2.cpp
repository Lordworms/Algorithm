/*
    https://www.luogu.com.cn/blog/ix-35/solution-cf1296e2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = ')' + s;
  vector<int> dp(n + 1, 1);
  vector<int> max_dp(26);
  for (int i = n; i >= 1; --i) {
    int c = s[i] - 'a';
    dp[i] = max_dp[c] + 1;
    for (int j = c + 1; j < 26; ++j) {
      max_dp[j] = max(max_dp[j], dp[i]);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << dp[i] << " \n"[i == n];
  }
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