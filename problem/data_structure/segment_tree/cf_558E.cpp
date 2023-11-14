#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int n, q;
struct node {
  int l, r, v; // v indicates whether it is the same element or not
  int lazy;
};
const int MAXN = 1e5 + 10;
node tr[26][MAXN * 8];
int cnt[26][MAXN];
string s;
void push_up(int c, int id) {
  tr[id][c].v = tr[id][c << 1].v + tr[id][c << 1 | 1].v;
}
void build(int c, int l, int r, int id) {
  if (l == r) {
    tr[id][c] = {l, r, s[l] == 'a' + id, -1};
    return;
  }
  tr[id][c] = {l, r, 0, -1};
  int m = (l + r) >> 1;
  build(c << 1, l, m, id);
  build(c << 1 | 1, m + 1, r, id);
  push_up(c, id);
}
void push_down(int c, int id) {
  if (tr[id][c].lazy != -1) {
    auto& laz = tr[id][c].lazy;
    tr[id][c << 1].lazy = tr[id][c << 1 | 1].lazy = laz;
    tr[id][c << 1].v = laz * (tr[id][c << 1].r - tr[id][c << 1].l + 1);
    tr[id][c << 1 | 1].v = laz * (tr[id][c << 1 | 1].r - tr[id][c << 1 | 1].l + 1);
    laz = -1;
  }  
}
void update(int c, int l, int r, int id, int d) {
  if (l <= tr[id][c].l && r >= tr[id][c].r) {
    tr[id][c].lazy = d;
    tr[id][c].v = d * (tr[id][c].r - tr[id][c].l + 1);
    return;
  }
  push_down(c, id);
  int m = (tr[id][c].r + tr[id][c].l) >> 1;
  if (l <= m) {
    update(c << 1, l, r, id, d);
  }
  if (r > m) {
    update(c << 1 | 1, l, r, id, d);
  }
  push_up(c, id);
}
int query(int c, int l, int r, int id) {
  if (l <= tr[id][c].l && r >= tr[id][c].r) {
    return tr[id][c].v;
  }
  push_down(c, id);
  int ans = 0;
  int m = (tr[id][c].r + tr[id][c].l) >> 1;
  if (l <= m) {
    ans += query(c << 1, l, r, id);
  }
  if (r > m) {
    ans += query(c << 1 | 1, l, r, id);
  }
  return ans;
}
void trav(int c, int id) {
  if (tr[id][c].l == tr[id][c].r) {
    if (tr[id][c].v == 1) {
      s[tr[id][c].l] = id + 'a';
    }
    return;
  }
  push_down(c, id);
  trav(c << 1, id);
  trav(c << 1 | 1, id);
}
void solve() {
  cin >> n >> q;
  cin >> s;
  s = ')' + s;
  for (int i = 0; i < 26; ++i) {
    build(1, 1, n, i);
  }
  int l, r, k;
  while (q--) {
    cin >> l >> r >> k;
    if (k) {
      int cur = l, len;
      for (int i = 0; i < 26; ++i) {
        len = query(1, l, r, i);
        if (len == 0) continue;
        update(1, l, r, i, 0);
        update(1, cur, cur + len - 1, i, 1);
        cur += len;
      }
    } else {
      int cur = r, len;
      for (int i = 0; i < 26; ++i) {
        len = query(1, l, r, i);
        if (len == 0) continue;
        update(1, l, r, i, 0);
        update(1, cur - len + 1, cur , i, 1);
        cur -= len;
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    trav(1, i);
  }
  s = s.substr(1);
  cout << s << '\n';
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
//   freopen("D:/code/Algorithm/in", "r", stdin);
//   freopen("D:/code/Algorithm/out", "w", stdout);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}