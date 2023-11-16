#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
  int l, r;
  ll v;
};
const int MAXN = 2e5 + 10;
node tr[MAXN * 16];
int root[MAXN * 16], sum[MAXN * 16], arr[MAXN * 16], tmp[MAXN * 16];
int cnt, n, len, q;
int getid(const int &v) { return lower_bound(arr + 1, arr + 1 + len, v) - arr; }
int build(int l, int r) {
  int root = ++cnt;
  if (l == r) return root;
  int m = (l + r) >> 1;
  tr[root].l = build(l, m);
  tr[root].r = build(m + 1, r);
  return root;
}
int update(int c, int l, int r, int rt) {
  int cur = ++cnt;
  tr[cur].l = tr[rt].l, tr[cur].r = tr[rt].r;
  sum[cur] = sum[rt] + 1;
  if (l == r) return cur;
  int m = (l + r) >> 1;
  if (c <= m) {
    tr[cur].l = update(c, l, m, tr[cur].l);
  } else {
    tr[cur].r = update(c, m + 1, r, tr[cur].r);
  }
  return cur;
}
int query(int lv, int rv, int l, int r, int k) {
  int m = (l + r) >> 1, extra = sum[tr[rv].l] - sum[tr[lv].l];
  if (l == r) return l;
  if (extra >= k) {
    return query(tr[lv].l, tr[rv].l, l, m, k);
  } else {
    return query(tr[lv].r, tr[rv].r, m + 1, r, k - extra);
  }
}
int main() {
#ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt", "r", stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt", "w", stdout);
#endif
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> tmp[i];
  }
  memcpy(arr, tmp, sizeof(tmp));
  sort(arr + 1, arr + n + 1);
  len = unique(arr + 1, arr + 1 + n) - arr - 1;
  root[0] = build(1, len);
  for (int i = 1; i <= n; ++i) {
   // cout << "getid:" << getid(tmp[i]) << '\n';
   // cout << " :::" << getid(tmp[i]) << ' ' << 1 << ' ' << len << ' ' << root[i - 1] << '\n';
    root[i] = update(getid(tmp[i]), 1, len, root[i - 1]);
  }
  int l, r, k;
  while (q--) {
    cin >> l >> r >> k;
    int id = query(root[l - 1], root[r], 1, len, k);
    cout << arr[id] << '\n';
  }
  return 0;
}