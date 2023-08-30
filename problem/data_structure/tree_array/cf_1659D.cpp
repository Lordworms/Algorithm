#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
int C[MAXN];
int n;
struct fenwick {
  ll PartialSum[MAXN];
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
  inline void modify(int l, int r, ll v) {
    add(l, v);
    add(r + 1, -v);
  }
};
fenwick tr;
void solve() {
  cin >> n;
  ll sum = 0;
  fill(tr.PartialSum, tr.PartialSum + n + 2, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> C[i];
    sum += C[i];
    tr.modify(i, i, C[i]);
  }
  sum /= n;
  for (int i = n; i >= 1; --i) {
    int sub = 0;
    if (tr.get(i) == i) {  // means the 1 in position i always exists
      sub++;
      C[i] = 1;
    } else {
      C[i] = 0;
    }
    tr.modify(i - sum + 1, i, -1);
    sum -= sub;
  }
  for (int i = 1; i <= n; ++i) {
    cout << C[i] << " \n"[i == n];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}