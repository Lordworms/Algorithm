#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;
#define int ll
struct node {
  int l, r;
  ll v;
};
node tr[MAXN << 5];
ll a[MAXN];
int n, q, cnt;
int sum[MAXN << 5], rt[MAXN << 5];
int build(int l, int r) {
  int root = ++cnt;
  tr[root].l = l, tr[root].r = r;
  if (l == r) return root;
  int m = (l + r) >> 1;
  tr[root].l = build(l, m);
  tr[root].r = build(m + 1, r);
  return root;
}
int update(int pos, int l, int r, int pre) {
  int root = ++cnt, m = (l + r) >> 1;
  tr[root].l = tr[pre].l;
  tr[root].r = tr[pre].r;
  sum[root] = sum[pre] + 1;
  if (l == r) return root;
  if (pos <= m) {
    tr[root].l = update(pos, l, m, tr[pre].l);
  } else {
    tr[root].r = update(pos, m + 1, r, tr[pre].r);
  }
  return root;
}
ll query(int u, int v, int l, int r, int k) {
  if (l == r) return l;
  // the tree contains [l, r]
  int left = sum[tr[v].l] - sum[tr[u].l];
  int right = sum[tr[v].r] - sum[tr[u].r];
  int ans = -1, m = (l + r) >> 1;
  if (left > k) { 
    ans = query(tr[u].l, tr[v].l, l, m, k);   
  } 
  if (ans != -1) return ans;
  if (right > k) { 
    ans = query(tr[u].r, tr[v].r, m + 1, r, k);
  }
  return ans;
}
void solve() {
  cin >> n >> q;
  rt[0] = build(1, n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    rt[i] = update(a[i], 1, n, rt[i - 1]);
  }
  int l, r, k;
  while (q--) {
    cin >> l >> r >> k;
    k = (r - l + 1) / k;
    cout << query(rt[l - 1], rt[r], 1, n, k) << '\n';
  }
  return ;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("D:/code/Algorithm/in", "r", stdin);
  freopen("D:/code/Algorithm/out", "w", stdout);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}