#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int m, n;
  cin >> m >> n;
  long double ans = 0;
  for (double i = 1; i <= m; i += 1) {
    ans += i * (pow(i / m, n) - pow((i - 1) / m, n));  
  }
  cout << ans << '\n';
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