#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 7;
using pii = pair<ll, int>;
const int INF = 0x3f3f3f3f;
struct fenwick {
  ll PartialSum[MAXN];
  fenwick() {
    for (int i = 0; i < MAXN; i++) PartialSum[i] = 0;
  }
  inline void add(ll index, ll increase) {
    while (index < MAXN) {
      PartialSum[index] = max(increase, PartialSum[index]);
      index += index & -index;
    }
  }
  inline ll get(int index) {
    ll sum = -INF;
    while (index) {
      sum = max(sum, PartialSum[index]);
      index -= index & -index;
    }
    return sum;
  }
};
ll a[MAXN], ord[MAXN], dp[MAXN], sum[MAXN];
void solve() {
  int T;
  cin >> T;
  int n;
  fenwick tr;
  while (T--) {
   cin >> n;
   vector<pii> pre;
   for (int i = 1; i <= n; ++i) {
     tr.PartialSum[i] = -INF;
   }
   for (int i = 1; i <= n; ++i) {
     cin >> a[i];
     sum[i] = sum[i - 1] + a[i];
     pre.push_back({sum[i], -i});
   }
   sort(pre.begin(), pre.end());
   for (int i = 1; i <= n; ++i) {
     ord[-pre[i - 1].second] = i;
   }
   for (int i = 1; i <= n; ++i) {
     dp[i] = dp[i - 1] + (a[i] > 0 ? 1 : (a[i] < 0 ? -1 : 0));
     auto pp = tr.get(ord[i]);
     dp[i] = max(dp[i], tr.get(ord[i]) + i);
     if (sum[i] > 0) dp[i] = i;
     tr.add(ord[i], dp[i] - i);
   }
   cout << dp[n] << '\n';
   dp[0] = sum[0] = 0;
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