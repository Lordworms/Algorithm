/*
0
3
-1
3
2
3
-1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 1e5 + 10;
struct Node {
  int l, r, v, laz;
};
struct Query {
  int x, y, k;
};
Node tr[MAXN << 2];
void push_down(int c) {
  if (tr[c].laz) {
    int &laz = tr[c].laz;
    tr[c << 1].v = laz;
    tr[c << 1].laz = laz;
    tr[c << 1 | 1].v = laz;
    tr[c << 1 | 1].laz = laz;
    laz = 0; 
  }
}
void build(int c, int l, int r) {
  tr[c] = {l, r, 0};
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
}
void update(int c, int l, int r, int v) {
  if (tr[c].l >= l && tr[c].r <= r) {
    tr[c].v = v;
    tr[c].laz = v;
    return; 
  } 
  push_down(c);
  int m = (tr[c].l + tr[c].r) >> 1;
  if (l <= m) {
    update(c << 1, l, r, v);
  } 
  if (m < r) {
    update(c << 1 | 1, l, r, v);
  }
}
ll query(int c, int x) {
  if (tr[c].l == tr[c].r) {
    return tr[c].v;
  }
  push_down(c);
  int m = (tr[c].l + tr[c].r) >> 1;
  if (m >= x) {
    return query(c << 1, x);    
  } else {
    return query(c << 1 | 1, x);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  build(1, 1, 100000);
  build(1, 1, n);
  int type, x, y, k;
  vector<Query> q;
  while (m--) {
    cin >> type;
    if (type == 1) {
      cin >> x >> y >> k;
      update(1, y, y + k - 1, q.size() + 1);
      q.push_back({x, y, k});
    } else {
      cin >> x;
      if (x == 1) {
        x;
      }
      int id = query(1, x);
      if (id == 0) {
        cout << b[x] << '\n';
        continue;
      }
      id--;
      cout << a[q[id].x + x - q[id].y] << '\n';
    }
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