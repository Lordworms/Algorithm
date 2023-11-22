#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 10;
int debug_flag = 1;
#define DEBUG if (debug_flag) std::cout << "debug output:"
struct num {
  int v, pos;
};
struct node {
  int l, r;
  ll v;
};
node tr[MAXN << 5];
int rt[MAXN << 5], sum[MAXN << 5];
int cnt;
int a[MAXN];
int len;
map<int, int> ids;
map<int, int> ans;
int getid(int x) {
  return ids[x];
}
int build(int l, int r) {
  int root = ++cnt;
  int m = (l + r) >> 1;
  if (l == r) {
    return m;
  }
  tr[root].l = build(l, m);
  tr[root].r = build(m + 1, r);
  return root;
}
int update(int l, int r, int pos, int v, int pre) {
  int root = ++cnt;
  tr[root].l = tr[pre].l;
  tr[root].r = tr[pre].r;
  sum[root] = sum[pre] + 1;
  int m = (l + r) >> 1;
  if (l == r) {
    tr[root].v = v;
    return root;
  }
  if (pos <= m) {
    tr[root].l = update(l, m, pos, v, tr[pre].l);
  } else {
    tr[root].r = update(m + 1, r, pos, v, tr[pre].r);
  }
  return root;
}
ll query(int u, int v, int l, int r, int k) {
  int left = sum[tr[v].l] - sum[tr[u].l], m = (l + r) >> 1;  
  int right = sum[tr[v].r] - sum[tr[u].r];
  if (l == r) return l;
  if (left >= k) {
    return query(tr[u].l, tr[v].l, l, m, k);
  } else {
    return query(tr[u].r, tr[v].r, m + 1, r, k - left);
  } 
}
void solve() {
  int n;
  cin >> n;
  vector<num> tmp(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> tmp[i].v;
    tmp[i].pos = i;
  }
  sort(tmp.begin() + 1, tmp.end(), [&](num a, num b) {
    if (a.v == b.v) {
      return a.pos < b.pos;
    }
    return a.v > b.v;
  });
  for (int i = 1; i <= n; ++i) {
    a[i] = tmp[i].v;
  }
  len = unique(a + 1, a + 1 + n) - a - 1;
  for (int i = 1; i <= len; ++i) {
    ids[a[i]] = len - i + 1;
    ans[len - i + 1] = a[i];
  }
  rt[0] = build(1, len);
  for (int i = 1; i <= n; ++i) {
    rt[i] = update(1, len, getid(tmp[i].v), 1, rt[i - 1]);
  }
  int q, k, pos;
  cin >> q;
  while (q--) {
    cin >> k >> pos;
    pos = query(rt[0], rt[k], 1, len, pos);
    cout << ans[pos] << '\n';
  }
  return ;
}
int main() {
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