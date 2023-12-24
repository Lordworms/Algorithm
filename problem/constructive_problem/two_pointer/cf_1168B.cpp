#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  string s;
  cin >> s;
  ll n = s.size();
  vector<int> r(n + 1, n); // r[i] represents the right position starts with i
  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    r[i] = r[i + 1];
    for (int k = 1; i + 2 * k < r[i]; ++k) {
      if (s[i + k] == s[i] && s[i + 2 * k] == s[i]) {
        r[i] = i + 2 * k;
      }
    }      
    ans += (n - r[i]);
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
  while (T--) {
    solve();
  }
  return 0;
}