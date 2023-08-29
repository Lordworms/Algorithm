#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 1e5 + 10;
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
  cin >> n;
  vector<int> a(n + 1);
  ll total = 0;
  fenwick tr;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    total += i - 1 - tr.get(a[i]);
    tr.add(a[i], 1);
  }
  bool sign = total % 2 == 1;
  int q, l, r;
  cin >> q;
  while (q--) {
    cin >> l >> r;
    total = (r - l + 1) * (r - l) >> 1;
    if (total % 2) {
      sign = !sign;
    }
    cout << (sign ? "odd" : "even") << '\n'; 
  }
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