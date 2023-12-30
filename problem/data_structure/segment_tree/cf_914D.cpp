/*
    we only allowed one element which is not a multiple of x between [l, r]
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 2e5 + 100;
int arr[MAXN];
struct Node {
  int l, r, v;    
};
Node tr[MAXN << 4];
int gcd(int a, int b) {return b? gcd(b, a % b) : a;}
void push_up(int c) {
  tr[c].v = gcd(tr[c << 1].v, tr[c << 1 | 1].v);
}
void build(int c, int l, int r) {
  tr[c] = {l, r, 0};
  if (l == r) {
    cin >> tr[c].v; // important, should decrease lots of running time
    return;
  }
  int m = (l + r) >> 1;
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
  push_up(c);
}
void update(int c, int pos, int v) {
  if (tr[c].l == tr[c].r) {
    tr[c].v = v;
    return;
  }
  int m = (tr[c].l + tr[c].r) >> 1;
  if (m >= pos) {
    update(c << 1, pos, v);
  } else {
    update(c << 1 | 1, pos, v);
  } 
  push_up(c);
}
int query(int c, int l, int r, int x) {
  if (tr[c].l == tr[c].r) return 1;
  int res = 0;
  int m = (tr[c].l + tr[c].r) >> 1;
  if (l <= m && tr[c << 1].v % x != 0) {
    res = query(c << 1, l, r, x);
  }
  if (r > m && tr[c << 1 | 1].v % x != 0 && res <= 1) {
    res += query(c << 1 | 1, l, r, x);
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  build(1, 1, n);
  int q, type, l, r, pos, x; cin >> q;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> l >> r >> x;
      auto g = query(1, l, r, x);
      if (g > 1) {
        cout << "NO" << '\n';
      } else  {
        cout << "YES" << '\n';
      }
    } else {
      cin >> pos >> x;
      update(1, pos, x);
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