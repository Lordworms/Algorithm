#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define int ll
void solve() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  vector<int> a(n + 5);
  map<int, int> cnt;
  map<int, int> pos;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i]; 
    cnt[a[i]]++;
    pos[a[i]] = i;
  }
  for (int l = 1, r = pos[a[l]]; l <= n; l = r + 1, r = pos[a[l]]) {
    int m = 0;
    for (int i = l; i <= r; r = max(r, pos[a[i]]), ++i) {
      m = max(m, cnt[a[i]]);
    }
    ans = r - l + 1 - m;
  }
  cout << ans << '\n';
  return ;
}
signed main() {
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