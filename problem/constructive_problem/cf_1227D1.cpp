/*
  time complexity (nlogm^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define lowbit(x) (x & (-x))
struct query {
  int k, id, pos;
  bool operator < (const query  &tmp) const {
    return k == tmp.k ? id < tmp.id : k < tmp.k;
  }
};
struct node {
  int id, val;
  bool operator < (const node &tmp) const {
    return val == tmp.val ? id < tmp.id : val > tmp.val;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<node> a(n + 1);
  vector<int> org(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].val;
    a[i].id = i;
    org[i] = a[i].val;
  } 
  sort(a.begin() + 1, a.end());
  int m;
  cin >> m;
  vector<query> q(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].k >> q[i].pos;
    q[i].id = i;
  }
  sort(q.begin() + 1, q.end());
  vector<ll> tree(n << 2);
  auto sum = [&](int x) {
    ll res = 0;
    while (x) {
      res += tree[x];
      x -= lowbit(x);
    }
    return res;
  };
  auto add = [&](int x, int v) {
    while (x <= n) {
      tree[x] += v;
      x += lowbit(x);
    }
  };
  auto find = [&](int pos) {
    int l = 1, r = n, res = 0;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (sum(m) >= pos) {
        res = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return res;
  };
  vector<int> ans(m + 1);
  int cur = 0;
  for (int i = 1; i <= m; ++i) {
    while (cur < q[i].k) {
      add(a[++cur].id, 1);
    }
    ans[q[i].id] = org[find(q[i].pos)];
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << "\n";
  }
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}