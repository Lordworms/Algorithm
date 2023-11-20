#include <bits/stdc++.h>
using namespace std;
#define int ll
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
int a[MAXN];
const ll INF = INT_MAX;
struct node {
  int l, r;
  ll v;
};
node tr[MAXN << 5];
int in[MAXN], out[MAXN], dep[MAXN << 3], rt[MAXN << 5];
vector<vector<int>> E;
int cnt, d_cnt;
void push_up(int c) {
  tr[c].v = std::min(tr[tr[c].l].v, tr[tr[c].r].v);
}
int build(int l, int r) {
  int root = ++cnt;
  tr[root].v = INF;
  if (l == r) return root;
  int m = (l + r) >> 1;
  tr[root].l = build(l, m);
  tr[root].r = build(m + 1, r);
  return root;
}
int update(int l, int r, int pos, ll val, int pre) {
  int cur = ++cnt;
  tr[cur].l = tr[pre].l, tr[cur].r = tr[pre].r;
  if (l == r) {
    tr[cur].v = val;
    return cur;
  }
  int m = (l + r) >> 1;
  if (pos <= m) {
    tr[cur].l = update(l, m, pos, val, tr[pre].l);
  } else {
    tr[cur].r = update(m + 1, r, pos, val, tr[pre].r);
  }
  push_up(cur);
  return cur;
}
ll query(int ql, int qr, int l, int r, int root) {
  if (ql <= l && qr >= r) {
    return tr[root].v;
  }
  int m = (l + r) >> 1;
  ll ans = INF;
  if (ql <= m) {
    ans = min(ans, query(ql, qr, l, m, tr[root].l));
  } 
  if (qr > m) {
    ans = min(ans, query(ql, qr, m + 1, r, tr[root].r));
  }
  return ans;
}
void dfs(int c, int f) {
  in[c] = ++d_cnt;
  dep[c] = dep[f] + 1;
  for (int &v : E[c]) {
    if (v == f) continue;
    dfs(v, c);
  }
  out[c] = d_cnt;
}
void solve() {
  int n, root, u, v;
  cin >> n >> root;
  E.resize(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);  
  }
  dfs(root, 0);
  vector<int> id(n + 1);
  iota(id.begin(), id.end(), 0);
  sort(id.begin() + 1, id.end(), [&](int a, int b){
    return dep[a] < dep[b];
  });
  rt[0] = build(1, n);
  for (int i = 1; i <= n; ++i) {
    rt[i] = update(1, n, in[id[i]], a[id[i]], rt[i - 1]);
  }  // we arrange the same depth into t[id[i]]
  vector<int> t(n + 1);
  for (int i = 1, j = 1; i <= n; t[dep[id[i]]] = j, j = ++i) {
    while (j < n && dep[id[i]] == dep[id[j + 1]]) 
      ++j;
  }
  int maxd = -1;
  for (int i = 1; i <= n; ++i) {
    maxd = max(maxd, dep[i]);
  }
  int Q, p, q, x, k, las = 0;
  cin >> Q;
  for (int i = 1; i <= Q; ++i) {
    cin >> p >> q;
    x = (las + p) % n + 1, k = (las + q) % n;
    cout << (las = query(in[x], out[x], 1, n, rt[t[std::min(maxd, dep[x] + k)]])) << '\n';
  }
  return ;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}