#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  s = ')' + s;
  function<void(int, vector<int>&)> get = [&](int l, vector<int>& len) {
    vector<int> dp(2);
    for (int i = l; i <= n; ++i) {
      if (s[i] == '0') {
        dp[0]++; 
      } else {
        dp[1] = max(dp[1], dp[0]) + 1;
      }
      len[i] = max(dp[0], dp[1]);
    }
  };
  vector<int> f(n + 1), g(f);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') {
     get(i, f);
     s[i] = '0';
     get(i, g);
     for (int j = i; j <= n; ++j) {
       if(f[j] != g[j]) {
        s[i] = '1';
        break;
       }
     }
    } 
  }
  cout << s.substr(1) << '\n';
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