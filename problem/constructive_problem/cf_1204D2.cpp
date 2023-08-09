#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int n = s.size(), cnt_zero = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') ++cnt_zero;
    else if(cnt_zero) --cnt_zero;
    else s[i] = '0';
  }
  cout << s << '\n';
  return ;
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