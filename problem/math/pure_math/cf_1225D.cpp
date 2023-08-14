#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  map<vector<pair<int, int>>, int> mp;
  vector<pair<int, int>> v1, v2;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    v1.clear();
    v2.clear();
    cin >> a[i];
    int cur = a[i];
    for (int j = 2; j * j <= cur; ++j) {
      int cnt = 0;
      while (cur % j == 0) {
        ++cnt;
        cur /= j;
        cnt %= k;
      }
      if (!cnt) {
        continue;
      }
      v1.push_back({j, cnt});
      v2.push_back({j, k - cnt});
    }
    if (cur > 1) {
      v1.push_back({cur, 1});
      v2.push_back({cur, k - 1});
    }
    ans += mp[v2];
    mp[v1]++;
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