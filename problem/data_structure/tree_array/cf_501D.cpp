/*
  没懂，明天继续
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
int n;
struct fenwick {
  int PartialSum[MAXN];
  fenwick() {
    for (int i = 0; i < MAXN; i++) PartialSum[i] = 0;
  }
  inline void add(ll index, ll increase) {
    while (index <= n) {
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
  inline void init() {
    memset(PartialSum, 0 ,sizeof(PartialSum));
    for (int i = 1; i <= n; ++i) {
      add(i, 1);
    }
  }
};
void solve() {
  cin >> n;
  vector<int> p(n + 1), q(n + 1);
  for (int i = 1; i <= n; ++i) { // we let index starts from 1 in order not to get into infinite loop
    cin >> p[i];
    p[i]++;
  } 
  for (int i = 1; i <= n; ++i) {
    cin >> q[i];
    q[i]++;
  }
  fenwick tr;
  tr.init();
  vector<ll> f(n + 1);
  for (int i = 1; i < n; ++i) { // f[n - i] represent the number of number which is less than q[i]
    f[n - i] += tr.get(q[i] - 1);
    tr.add(q[i], -1);
  }
  tr.init();
  for (int i = 1; i < n; ++i) {
    f[n - i] += tr.get(p[i] - 1);
    tr.add(p[i], -1);
  }
  for (int i = 1; i < n; ++i) {
    f[i + 1] += f[i] / (i + 1); // now f[n - i] store the value ai in contor expandation
    f[i] %= (i + 1);
  }
  tr.init();
  int cur = 1;
  for (int i = n - 1; i >= 1; --i) {
    int l = 1, r = n, ans = -1, m;
    ll sum;
    while (l <= r) {
      m = (l + r) >> 1;
      sum = tr.get(m - 1);
      if (sum <= f[i]) {
        l = m + 1;
        ans = m;
      } else {
        r = m - 1;
      }
    }
    if (ans == -1) {
      ans = cur;
    }
    cout << ans - 1 << ' ';
    tr.add(ans, -1);
    while (!tr.PartialSum[cur]) ++cur;
  }
  for (int i = 1; i <= n; ++i) {
    if (tr.PartialSum[i]) {
      cout << i - 1 << '\n';
      break;
    }
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