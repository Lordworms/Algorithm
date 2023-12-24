#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
struct Prob {
  int t, p;
};
void solve() {
  int n, T, a, b;
  cin >> n >> T >> a >> b;
  vector<Prob> arr(n + 2);
  vector<int> cnt(2);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i].p;
    cnt[arr[i].p]++;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i].t;
  }
  sort(arr.begin() + 1, arr.begin() + 1 + n, [&] (Prob aa, Prob bb) {
    return aa.t < bb.t;
  });
  ll ans = 0, cur = 0;
  for (int i = 1; i <= n + 1; ++i) {
    int req = arr[i].t - 1;
    if (i == n + 1) {
      req = T;
    }
    if (i - 1) {
      cur += arr[i - 1].p ? b : a;
      cnt[arr[i - 1].p]--;
    }
    if (req >= cur) {
      req -= cur;
      int extraA = req / a;
      extraA = min(extraA, cnt[0]);
      int extraB = (req - a * extraA) / b;
      extraB = min(extraB, cnt[1]);
      ans = max(ans, 1ll * (i - 1 + extraB + extraA)); // use cnt[1], extraB to avoid extraB > cnt[1] situation
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}