#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
struct node {
  int l, r, v, laz;
};
const int LIM = 20;
node tr[N << 2][LIM];
int arr[N];
void push_up(int c, int bit) {
  tr[c][bit].v = tr[c << 1][bit].v + tr[c << 1 | 1][bit].v;
}
void push_down(int c, int bit) {
  int &laz = tr[c][bit].laz;
  if (laz) {
    tr[c << 1][bit].laz ^= 1;
    tr[c << 1 | 1][bit].laz ^= 1;
    tr[c << 1][bit].v =
        (tr[c << 1][bit].r - tr[c << 1][bit].l + 1) - tr[c << 1][bit].v;
    tr[c << 1 | 1][bit].v =
        (tr[c << 1 | 1][bit].r - tr[c << 1 | 1][bit].l + 1) -
        tr[c << 1 | 1][bit].v;
    laz = 0;
  }
}
void build(int l, int r, int c, int bit) {
  tr[c][bit] = {l, r, 0, 0};
  if (l == r) {
    tr[c][bit].v = ((arr[l] & (1 << bit)) != 0);
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, c << 1, bit);
  build(m + 1, r, c << 1 | 1, bit);
  push_up(c, bit);
}
void update(int c, int l, int r, int bit) {
  if (l <= tr[c][bit].l && r >= tr[c][bit].r) {
    tr[c][bit].laz ^= 1;
    tr[c][bit].v = (tr[c][bit].r - tr[c][bit].l + 1) - tr[c][bit].v;
    return;
  }
  push_down(c, bit);
  int mid = (tr[c][bit].l + tr[c][bit].r) >> 1;
  if (l <= mid) {
    update(c << 1, l, r, bit);
  }
  if (r > mid) {
    update(c << 1 | 1, l, r, bit);
  }
  push_up(c, bit);
}
ll query(int c, int l, int r, int bit) {
  if (l <= tr[c][bit].l && r >= tr[c][bit].r) {
    return tr[c][bit].v;
  }
  push_down(c, bit);
  int mid = (tr[c][bit].l + tr[c][bit].r) >> 1;
  ll ans = 0;
  if (mid >= l) {
    ans += query(c << 1, l, r, bit);
  } 
  if (r > mid) {
    ans += query(c << 1 | 1, l, r, bit);
  }
  return ans;
}
void solve() { 
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 0; i < 20; ++i) {
    build(1, n, 1, i);
  }
  int m, op, l, r;
  cin >> m;
  while (m --) {
    cin >> op;
    cin >> l >> r;
    if (op == 1) {
      ll ans = 0;
      for (int i = 0; i < 20; ++i) {
        ans += (1ll << i) * query(1, l, r, i); 
      }
      cout << ans << '\n';
    } else {
      int x;
      cin >> x;
      for (int i = 0; i < 20; ++i) {
        if (x & (1 << i)) update(1, l, r, i);
      }
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