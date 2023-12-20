#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
struct Point {
  int x, y;
  bool operator < (const Point &a) const { return y == a.y ? x > a.x : y > a.y; }
};
struct Node {
  int l, r, v;
};
Node tr[MAXN << 2];
int p[MAXN];
int siz;
int id(int x) {
  return lower_bound(p + 1, p + 1 + siz, x) - p;
}
void push_up(int c) { tr[c].v = tr[c << 1].v + tr[c << 1 | 1].v; }
void build(int c, int l, int r) {
  tr[c] = {l, r, 0};
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
}
void update(int c, int pos, int x) {
  if (tr[c].l == tr[c].r) {
    tr[c].v = x;
    return;
  }
  int m = (tr[c].l + tr[c].r) >> 1;
  if (pos <= m) {
    update(c << 1, pos, x);
  } else {
    update(c << 1 | 1, pos, x);
  }
  push_up(c);
}
ll query(int c, int ql, int qr) {
  if (tr[c].l >= ql && tr[c].r <= qr) {
    return tr[c].v;
  }
  int m = (tr[c].l + tr[c].r) >> 1;
  ll res = 0;
  if (ql <= m) {
    res += query(c << 1, ql, qr);
  }
  if (qr > m) {
    res += query(c << 1 | 1, ql, qr);
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<Point> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
    p[i] = a[i].x;
  }
  sort(p + 1, p + 1 + n);
  siz = unique(p + 1, p + 1 + n) - p - 1;
  build(1, 1, siz);
  for (int i = 1; i <= n; ++i) a[i].x = id(a[i].x);
  sort(a.begin() + 1, a.end());
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    update(1, a[i].x, 1);
    ans += 1ll * query(1, (a[i + 1].y == a[i].y ? a[i + 1].x + 1 : 1), a[i].x) * query(1, a[i].x, siz); // should plus 1
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
  while (T--) {
    solve();
  }
  return 0;
}