#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
#define int ll
struct skill {
  int id, v;
  bool operator < (const skill &a) const {
    return v < a.v;
  }
};
void solve() {
  int n, A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  vector<skill> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].id = i;
    cin >> a[i].v;
  }
  sort(a.begin() + 1, a.end(), [&](skill aa, skill bb) {
    return aa.v < bb.v;
  });
  ll cur = n;
  vector<int> sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i].v;
  }
  pair<ll, pair<ll, ll>> ans;
  for (int i = 0; i <= n; ++i) {
    int rem = m - (i * A - (sum[n] - sum[n - i]));
    if (rem < 0) break;
    // rem 
    cur = min(cur, 1ll * (n - i));
    while (cur > 1 && rem < (cur * a[cur].v - sum[cur])) --cur; // to get the maximum minimum
    rem -= (cur * a[cur].v - sum[cur]);
    int min_level = min(A, (i == n? A : (a[cur].v + rem / cur)));
    ans = std::max(ans, {i * cf + min_level * cm, {i, min_level}});
  }
  cout << ans.first << '\n';
  for (int i = 0; i < ans.second.first; ++i) {
    a[n - i].v = A;
  }
  // ans: finalanswer, {changed to max nunmber, minimal level}
  for (int i = 1; i <= n; ++i) {
    a[i].v = std::max(a[i].v, ans.second.second);
  }
  sort(a.begin() + 1, a.end(), [&](skill a, skill b) {
    return a.id < b.id;
  });
  for (int i = 1; i <= n; ++i) {
    cout << a[i].v << " \n" [i == n];
  }
  return;
}
signed main() {
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