#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 20;
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
  int n, q, op, x, y, xx, yy;
  cin >> n >> q;
  vector<int> r(n + 1), c(n + 1);
  fenwick row, col;
  while (q--) {
    cin >> op;
    switch (op) {
      case 1: {  // put
        cin >> x >> y;
        r[x]++;
        if (r[x] == 1) row.add(x, 1);
        c[y]++;
        if (c[y] == 1) col.add(y, 1);
        break;
      }
      case 2: {
        cin >> x >> y;
        r[x]--;
        if (r[x] == 0) row.add(x, -1);
        c[y]--;
        if (c[y] == 0) col.add(y, -1);
        break;
      }
      case 3: {
        cin >> x >> y;
        cin >> xx >> yy;
        if (xx - x + 1 == row.get(xx) - row.get(x - 1) || // the whole row or column all contains rook
            yy - y + 1 == col.get(yy) - col.get(y - 1)) {
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
        break;
      }
      default:
        break;
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