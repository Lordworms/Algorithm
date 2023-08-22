#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m + 1), p(n + 1);
  iota(p.begin(), p.end(), 0);
  vector<vector<int>> pos(n + 1);
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> x[i];
    pos[x[i]].push_back(i);
    if (i != 1) {
      ans += abs(x[i - 1] - x[i]);
    }
  } 
  cout << ans << ' ';
  for (int i = 2; i <= n; ++i) {
    // i previous in position
    for (int k : pos[i]) {
      if (k > 1) {
        ans -= abs(i - p[x[k - 1]]);
      } 
      if (k < m) {
        ans -= abs(i - p[x[k + 1]]);
      }
    }
    // i - 1 previous in position 1
    for (int k : pos[i - 1]) {
      if (k > 1 && x[k - 1] != i) {
        ans -= abs(1 - p[x[k - 1]]);
      }
      if (k < m && x[k + 1] != i) {
        ans -= abs(1 - p[x[k + 1]]);
      }
    }
    p[i] = 1;
    p[i - 1] = i;
    // i now in position 1
    for (int k : pos[i]) {
      if (k > 1) {
        ans += abs(1 - p[x[k - 1]]);
      }
      if (k < m) {
        ans += abs(1 - p[x[k + 1]]);
      }
    } 
    // i - 1 now in position i
    for (int k : pos[i - 1]) {
      if (k > 1 && x[k - 1] != i) {
        ans += abs(i - p[x[k - 1]]);
      }
      if (k < m && x[k + 1] != i) {
        ans += abs(i - p[x[k + 1]]);
      }
    }
    cout << ans << ' ';
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