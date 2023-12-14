#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  string s;
  cin >> s;
  ll n = s.size();
  s += s;
  ll con = 0, cur = 0;
  for (auto &c : s) {
    cur = c == '1' ? cur + 1 : 0;
    con = max(con, cur);
  }
  if (con == 0) {
    cout << 0 << '\n';
  } else if (con >= s.size()) {
    cout << n * n << '\n';
  } else {
    cout << ((con + 1) / 2) * ((con + 2) / 2) << '\n';    
  }
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}