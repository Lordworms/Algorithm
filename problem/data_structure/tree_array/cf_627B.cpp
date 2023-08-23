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
  ll n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  vector<ll> A(n + 1);
  int type;
  fenwick t1, t2;
  int x, y;
  while (q--) {
    cin >> type;
    switch (type) {
      case 1: {
        cin >> x >> y;
        auto cur = A[x];
        A[x] += y;
        t1.add(x, min(b, A[x]) - min(b, cur));
        t2.add(x, min(a, A[x]) - min(a, cur));
        break;
      }
      case 2: {
        cin >> x;
        cout << t1.get(x - 1) + t2.get(n) - t2.get(x + k - 1) << '\n';
        break;
      }
      default: {
        break;
      }
    }
  }
  return;
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