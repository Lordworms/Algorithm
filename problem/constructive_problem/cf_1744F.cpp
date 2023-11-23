#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, p;
  cin >> n;
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p;
    pos[p] = i;
  }
  int l = pos[0], r = pos[0];
  ll res = 1;
  for (int len = 2; len <= n; ++len) {
    // mex means the posistion which contains max
    int mex = (len - 1) >> 1;
    // we want to include the range which contains all element in [0, (len - 1) / 2]
    l = std::min({l, n - len + 1, pos[mex]});
    r = std::max({r, len, pos[mex]});
    // adding the results which has length of len and contains [l,r]
    res += std::max(0, len - (r - l + 1) + 1);
  }
  cout << res << '\n';
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
//   freopen("D:/code/Algorithm/in", "r", stdin);
//   freopen("D:/code/Algorithm/out", "w", stdout);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}