/*
    one element exists once in a range <-> the last position occurs less than l
    use segment tree to do the job
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 100;
//const int MAXN = 10;
using pii = pair<int, int>;
pii tr[MAXN << 2];
int n;
int pre[MAXN], cur[MAXN];
struct Que {
  int l, r, id;
};
map<int, pii> mark;
vector<Que> q;
void push_up(int c) {
  tr[c] = min(tr[c << 1], tr[c << 1 | 1]);
}
void update(int c, int l, int r, int pos, int val) {
  if (l == r) {
    mark[c] = make_pair(val, pos);
    tr[c] = make_pair(val, pos);
  } else {
    int m = (l + r) >> 1;
    if (pos <= m) {
      update(c << 1, l, m, pos, val);
    } else {
      update(c << 1 | 1, m + 1, r, pos, val);
    }
    push_up(c);
  }
}
pii query(int c, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) {
    return tr[c];
  }
  int m = (l + r) >> 1;
  pii ans = make_pair(n + 1, 0);
  if (ql <= m) {
    ans = query(c << 1, l, m, ql, qr);
  } 
  if (qr > m) {
    ans = min(ans, query(c << 1 | 1, m + 1, r, ql, qr));
  }
  return ans;
}
void solve() {
  int m, l, r, w;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre[i] = cur[a[i]];
    cur[a[i]] = i;
  }
  cin >> m;
  q.push_back({0, 0, 0});
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r;
    q.push_back({l, r, i});
  }
  memset(tr, 127, sizeof(tr));
  sort(q.begin() + 1, q.end(), [&](Que a, Que b) {
    return a.r < b.r;
  });
  vector<int> ans(m + 1);
  for (int i = 1, j = 1; i <= m; ++i) {
    for (; j <= q[i].r && j <= n; ++j) {
      if (pre[j]) {
        update(1, 1, n, pre[j], n + 1); // could not apply since we have an extra same element backwards
      }
      update(1, 1, n, j, pre[j]);
    }
    pii res = query(1, 1, n, q[i].l, q[i].r);
    if (res.first < q[i].l) ans[q[i].id] = a[res.second]; 
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << "\n";
  }
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