#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() { 
  int n, k;
  string s;
  cin >> n >> k >> s;
  s = ')' + s;
  int one = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') {
      one++;
    }
  }
  int cur = 0, ans = 0x3f3f3f3f;
  for (int i = 1;i <= k; ++i) {
    cur = 0;
    for (int j = i; j <= n; j+=k) {
      if (s[j] == '1') {
        ++cur;
      } else {
        --cur;
      }
      cur = max(cur, 0);
      ans = min(ans, one - cur);
    }
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
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}