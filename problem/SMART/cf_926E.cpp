/*
    really smart way to write code!

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n;
  cin >> n;
  int len = 0, x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    while (x == a[len]) --len, ++x;
    ++len;
    a[len] = x; 
  }
  cout << len << '\n';
  for (int i = 1; i <= len; ++i) cout << a[i] << " \n" [i == n];
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