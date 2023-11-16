#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  ll n, m, a, b, ans;
  cin >> a >> b >> n >> m;
  // all first day
  ans = a * m * (n / (m + 1));
  ans += a * (n % (m + 1));
  // most first day part second
  ans = min(ans, a * (n / (m + 1)) * m + b * (n % (m + 1)));
  // all second
  ans = min(ans, b * n);
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