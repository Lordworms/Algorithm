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
  s = '*' + s;
  vector<ll> sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
  } 
  sort(sum.begin(), sum.end());
  ll total = 0;
  for (int i = 1; i <= n; ++i) {
    total += i * (n - i + 1);
  }
  for (int i = 1; i <= n; ++i) {
    total += i * sum[i];
  }
  for (int i = 0 ; i <= n - 1; ++i) {
    total -= (n - i) * sum[i];
  }
  total >>= 1;
  stack<ll> st;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      st.push(i);
    } else if (!st.empty()) {
      total -= st.top() * (n - i + 1);
      st.pop();
    }
  }
  cout << total << '\n';
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