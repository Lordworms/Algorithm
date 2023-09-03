#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> cards(n + 1, vector<int>(k));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> cards[i][j];
    }
  }
  map<vector<int>, int> mp;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      vector<int> v(k);
      for (int kk = 0; kk < k; ++kk) {
        v[kk] = (6 - cards[i][kk] - cards[j][kk]) % 3;
      }
      mp[v]++;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt = mp[cards[i]];
    ans += cnt * (cnt - 1) >> 1;
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