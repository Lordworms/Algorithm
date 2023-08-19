#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 10;
void solve() {
  string s;
  int q, k;
  cin >> q;
  for (int i = 1; i < MAXN; ++i) {
    s += std::to_string(i);
  }
  while (q--) {
    cin >> k;
    ll biggest = 1, total_length = 1, tmp;
    while (k > total_length) {
      k -= total_length;
      ++biggest;
      tmp = biggest;
      while (tmp) {
        ++total_length;
        tmp /= 10;
      }
    }
    cout << s[k - 1] << '\n';
  }
  return;
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