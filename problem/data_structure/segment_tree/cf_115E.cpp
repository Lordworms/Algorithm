#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
const ll inf = (1ll << 60);
struct node {
  int l, r;
  ll v, add;
}; // v represent maximum
node tr[MAXN * 4];
void push_up(int c) {
  tr[c].v = max(tr[c << 1].v, tr[c << 1 | 1].v);
}
void push_down(int c) {
  if (tr[c].add) {
    auto &add = tr[c].add;
    tr[c << 1].v += add;
    tr[c << 1 | 1].v += add;
    tr[c << 1].add += add;
    tr[c << 1 | 1].add += add;
    add = 0;
  }
}
void build(int c, int l, int r) {
  tr[c] = {l, r, 0, 0};
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
  push_up(c);
}
void update(int c, int l, int r, int v) {
  if (l <= tr[c].l && r >= tr[c].r) {
    tr[c].v += v;
    tr[c].add += v;
    return;
  }
  push_down(c);
  int m = (tr[c].l + tr[c].r) >> 1;
  if (m >= l) {
    update(c << 1, l, r, v);
  }
  if (m < r) {
    update(c << 1 | 1, l, r, v);
  }
  push_up(c);
}
void update_single(int c, int pos, ll v) {
  if (tr[c].l == tr[c].r) {
    tr[c].add = 0, tr[c].v = v;
    return;
  }
  push_down(c);
  int m = (tr[c].l + tr[c].r) >> 1;
  if (m >= pos) {
    update_single(c << 1, pos, v);
  } else {
    update_single(c << 1 | 1, pos, v);
  }
  push_up(c);
}
ll query(int c, int ql, int qr) {
  if (ql <= tr[c].l && qr >= tr[c].r) {
    return tr[c].v;
  }  
  push_down(c);
  int m = (tr[c].l + tr[c].r) >> 1;
  ll res = -inf;
  if (ql <= m) {
    res = max(res, query(c << 1, ql, qr));
  } 
  if (qr > m) {
    res = max(res, query(c << 1 | 1, ql, qr));
  }
  return res;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> cost(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }
  int l, r, p;
  vector<vector<int>> road(n + 1);
  vector<vector<ll>> rev(n + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r >> p;
    road[r].push_back(l);
    rev[r].push_back(p);
  }
  vector<ll> dp(n + 1);
  build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    update(1, 0, i - 1, -cost[i]); //minus the cost since we should build a new road
    for (int j = 0; j < road[i].size(); ++j) {
      ll re = rev[i][j];
      int l = road[i][j];
      update(1, 0, l - 1, re); // get the extra revenue since we build the road already
    }
    dp[i] = max(query(1, 0, i - 1), dp[i - 1]); // calculate the maximum answer
    update_single(1, i, dp[i]); // update the corresponding position (key!!!!, update single point to store previous answer)
  }
  cout << dp[n] << '\n';
  return ;
}
signed main() {
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