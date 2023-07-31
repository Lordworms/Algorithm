#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> cnt(26);
  function<bool(int, int)> check =
      [&](int total, int rep) {  // total: the number of current
        for (int i = 0; i < 26; ++i) {
          total -= cnt[i] / rep;
          if (total <= 0) return true;
        }
        return false;
      };
  string s;
  ll ans = 0;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    cnt[s[i] - 'a']++;
    ans = max(ans, cnt[s[i] - 'a']);
  }
  vector<int> fac;
  for (int i = 2; i <= k; ++i) {
    if (k % i == 0) {
      fac.push_back(i);
    }
  }

  for (int &f : fac) {
    int l = 1, r = n / f;  // 循环节的数量
    while (l <= r) {
      int mid = (l + r) >> 1;  //
      if (check(f, mid)) {
        ans = max(ans, 1ll * mid * f);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}