#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
struct node {
  int l, r;
  ll add, sum;
};
node tree[MAXN << 2];
int a[MAXN];
int dfn[MAXN], in[MAXN], out[MAXN], color[MAXN];
int id;
vector<vector<int>> E;
void dfs(int cur, int fa) {
  in[cur] = ++id;
  dfn[id] = cur;
  for (int &v : E[cur]) {
    if (v == fa) continue;
    dfs(v, cur);
  }
  out[cur] = id;
}
void push_up(int c) {
  tree[c].sum = tree[c << 1 | 1].sum + tree[c << 1].sum;
  return;
}
void push_down(int c) {
  if (tree[c].add) {
    tree[c << 1 | 1].add ^= 1;
    tree[c << 1].add ^= 1;
    auto &add = tree[c].add;
    tree[c << 1].sum += (tree[c << 1].r - tree[c << 1].l + 1) - tree[c << 1].sum;
    tree[c << 1 | 1].sum = (tree[c << 1 | 1].r - tree[c << 1 | 1].l + 1) - tree[c << 1 | 1].sum;
    tree[c].add = 0;
  }
}
void build(int c, int l, int r) {
  tree[c].l = l;
  tree[c].r = r;
  tree[c].sum = tree[c].add = 0;
  if (l == r) {
    tree[c].sum = color[dfn[l]];
    return;
  }
  int m = (l + r) >> 1;
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
  push_up(c);
}
void modify (int c, int l , int r) {
  if (tree[c].r < l || tree[c].l> r) return;
  if (tree[c].l >= l && tree[c].r <= r) {
    tree[c].add ^= 1;
    tree[c].sum = (tree[c].r - tree[c].l + 1) - tree[c].sum;
    return;  
  }
  push_down(c);
  int m = (tree[c].l + tree[c].r) >> 1;
  if (m >= l) {
    modify(c << 1, l, r);
  } 
  if (m < r) {
    modify(c << 1 | 1, l, r); 
  }
  push_up(c);
}
ll query(int c, int l, int r) {
  if (tree[c].r < l || tree[c].l> r) return 0;
  if (tree[c].l >= l && tree[c].r <= r) {
    return tree[c].sum;
  }
  push_down(c);
  int m = (tree[c].l + tree[c].r) >> 1;
  ll ans = 0;
  if (m >= l) ans += query(c << 1, l, r);
  if (m < r) ans += query(c << 1 | 1, l, r);
  push_up(c);
  return ans;
}
void solve() {
  int n, fa;
  cin >> n;
  E.resize(n + 1);
  vector<int> c(n + 1);
  for (int i = 2; i <= n; ++i) {
    cin >> fa;
    E[fa].push_back(i);
    E[i].push_back(fa);
  }
  for (int i = 1; i <= n; ++i) cin >> color[i];
  dfs(1, -1);
  build(1, 1, n);
  int q, x;
  cin >> q;
  string op;
  while (q--) {
    cin >> op >> x;
    if (op == "get") {
      cout << query(1, in[x], out[x]) << '\n';
    } else {
      modify(1, in[x], out[x]);
    }
  }
  return ;
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