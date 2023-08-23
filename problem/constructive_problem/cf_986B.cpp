#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    while (a[i] != i) {
      swap(a[i], a[a[i]]);
      ++ans;
    }
  } 
  if (n % 2 == ans % 2) {
    cout << "Petr" << '\n';
  } else {
    cout << "Um_nik" << '\n';
  }
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