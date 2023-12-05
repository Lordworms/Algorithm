#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int MOD = 1e9+7;
const int MAXN = 1e5 + 100;
const int LEN = 31;
struct node {
  int l, r, v, lazy;
};
node tr[MAXN << 5];
int arr[MAXN];
using pii = pair<pair<int, int>, int>;
void push_down(int c) {
  if (tr[c].lazy) {
    int &laz = tr[c].lazy;
    tr[c << 1].v |= laz;
    tr[c << 1 | 1].v |= laz;
    tr[c << 1].lazy |= laz;
    tr[c << 1 | 1].lazy |= laz;
    laz = 0;
  }
}
void push_up(int c) {
  tr[c].v = tr[c << 1].v & tr[c << 1 | 1].v;
}
void build(int c, int l, int r) {
  int m = (l + r) >> 1;
  tr[c] = {l, r, 0, 0};
  if (l == r) {
    return; 
  }
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
}
void update(int l, int r, int c, int v) {
  if (l <= tr[c].l && r >= tr[c].r) {
    tr[c].v |= v;
    tr[c].lazy |= v;
    return;
  }
  push_down(c);
  int m = (tr[c].l + tr[c].r) >> 1;
  if (l <= m) {
    update(l, r, c << 1, v);
  }
  if (r > m) {
    update(l, r, c << 1 | 1, v);
  }
  push_up(c);
}
int query(int l, int r, int c) {
  if (l <= tr[c].l && r >= tr[c].r) {
    return tr[c].v;
  }
  push_down(c);
  int m = (tr[c].l + tr[c].r) >> 1;
  int ans = (1ll << 31) - 1;
  if (l <= m) {
    ans &= query(l, r, c << 1);
  }
  if (r > m) {
    ans &= query(l, r, c << 1 | 1);
  }
  return ans;
}
void solve() {
  int n, m, l, r, rr;
  cin >> n >> m;
  build(1, 1, n);
  vector<vector<int>> Q;
  while (m--) {
    cin >> l >> r >> rr;
    if (l > r) swap(l, r);
    Q.push_back({l, r, rr});
    update(l, r, 1, rr);
  }
  bool is_valid = true;
  for (auto &q : Q) {
    int &l = q[0];
    int &r = q[1];
    int &res = q[2];
    if (query(l, r, 1) != res) {
      is_valid = false;
      break;
    }
  }
  if (is_valid) {
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i) {
      cout << query(i, i, 1) << " \n" [i == n];
    }
  } else {
    cout << "NO" << '\n';
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