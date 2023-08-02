#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a;
  a.push_back(0);
  int cur_max = 0;
  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;
    if (x > cur_max) {
      a.push_back(0);
      cur_max = x;
    }
    a[a.size() - 1]++;
  }
  vector<int> dp(n + 1);
  /*
    transformed into a dp problem
  */
  dp[0] = 1;
  for (int i = 1; i < a.size(); ++i) {
    for (int j = n; j >= a[i]; --j) {
      dp[j] |= dp[j - a[i]];
    }
  }
  cout << (dp[n] ? "YES" : "NO") << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}