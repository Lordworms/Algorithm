#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
using pii = pair<int, int>;
void solve() {
  int n, p, x, y;
  cin >> n >> p;
  map<pii, int> mp;
  vector<int> cnt(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    cnt[x]++, cnt[y]++;
    if (x > y) swap(x, y);
    mp[{x, y}]++;
  }
  vector<int> tmp(n + 1);
  for (int i = 1; i <= n; ++i) tmp[i] = cnt[i];
  sort(tmp.begin() + 1, tmp.end());
  ll ans = 0;
  for (int i = n; i >= 1; --i) {
    int r = i - 1, l = 1, m, v = std::max(0, p - tmp[i]), pos = i; // judge 0!
    while (l <= r) {
      m = (l + r) >> 1;
      if (tmp[m] >= v) {
        pos = m;
        r = m - 1;    
      } else {
        l = m + 1;
      }
    }    
    ans += i - pos;
  }
  for (auto &k : mp) {
    int x = k.first.first;
    int y = k.first.second;
    // repeat calculation
    if (cnt[x] + cnt[y] >= p && cnt[x] + cnt[y] - k.second < p) {
      --ans;
    }
  }
  cout << ans << '\n';
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