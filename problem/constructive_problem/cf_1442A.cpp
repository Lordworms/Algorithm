#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  bool flag = 1;
  int n;
  cin >> n;
  vector<int> v(n + 1), a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) cin >> v[i];
  /*
    a[i] <= a[i - 1]
    b[i] >= b[i - 1]
    a[i] <= v[i]
    b[i] <= v[i]
    a[i] + b[i] = v[i]
    v[i] - a[i] >= b[i - 1]
    a[i] <=  v[i] - b[i - 1]
  */
  a[1] = v[1];
  b[1] = 0;
  for (int i = 2; i <= n; ++i) {
    a[i] = min(a[i - 1], v[i] - b[i - 1]);
    b[i] = v[i] - a[i];
    if (b[i] > v[i] || b[i] < 0) {
      flag = false;
      break;
    } 
  }
  if (flag) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
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