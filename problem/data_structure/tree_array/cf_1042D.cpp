#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
struct fenwick {
  ll PartialSum[MAXN];
  fenwick() {
    for (int i = 0; i < MAXN; i++) PartialSum[i] = 0;
  }
  inline void add(ll index, ll increase) {
    while (index < MAXN) {
      PartialSum[index] += increase;
      index += index & -index;
    }
  }
  inline ll get(int index) {
    ll sum = 0;
    while (index) {
      sum += PartialSum[index];
      index -= index & -index;
    }
    return sum;
  }
};
void solve() {
  int n;
  ll t;
  cin >> n >> t;
  fenwick tr;
  vector<int> a(n + 1);
  vector<ll> sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  } 
  sort(sum.begin(), sum.end());
  ll pre = 0;
  ll ans = 0;
  //sum[r] - sum[l - 1] < t <=> sum[r] - t < sum[l - 1];
  //多体会一下！！！！
  for (int i = 1; i <= n; ++i) {
    int l = upper_bound(sum.begin(), sum.end(), pre) - sum.begin();
    tr.add(l, 1);
    pre += a[i];
    int r = upper_bound(sum.begin(), sum.end(), pre - t) - sum.begin();
    ans += tr.get(n + 1) - tr.get(r);
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