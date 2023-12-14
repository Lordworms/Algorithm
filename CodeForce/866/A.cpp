#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  string s;
  cin >> s;
  int len = s.size();
  if (s == "^") {
    cout << 1 << '\n';
    return;
  }
  int ans = 0;
  if (s[0] == '_') {
    ++ans;
  } 
  if (s.back() == '_') {
    ++ans;
  }
  for (int i = 0; i < len - 1; ++i) {
    if (s[i] == s[i + 1] && s[i] == '_') {
      ++ans;
    }
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}