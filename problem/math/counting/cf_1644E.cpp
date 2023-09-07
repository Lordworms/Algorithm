#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define int ll
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = '0' + s;
  bool flag = false;
  auto calc = [&] (string &s, char c) {
    int pre = 0;
    // first we calculate how many characters left in this column
    for (char& cc: s) {
      pre += (cc == c);
    }
    bool pre_have = false;
    ll ans = 0;
    for (int i = 0 ; i <= s.size() - 1; ++i) {
      if (s[i] == c) {
        pre_have = true;
        --pre;
      }
      if (i == s.size() - 1 || s[i + 1] == (c == 'D' ? 'R' : 'D')) {
        ans += pre_have ? pre : n - 1;
      }
    }
    return ans;
  };
  int numr = 0, numd = 0;
  for (int i = 0 ; i < s.size(); ++i) {
    if (s[i] == 'R') numr++;
    if (s[i] == 'D') numd++;
  }
  if (!numr || !numd) {
    cout << n << '\n';
    return;
  }
  cout << n * n - calc(s, 'R') - calc(s, 'D') << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}