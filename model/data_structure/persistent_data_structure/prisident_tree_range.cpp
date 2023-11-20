#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
#define id(x) (lower_bound(tmp + 1, tmp + len + 1, x) - tmp)
struct node {
  int l, r;
  ll v;
};
node tr[MAXN << 4];
int root[MAXN << 4];
ll sum[MAXN << 4];
int arr[MAXN], tmp[MAXN];
int cnt;
int build(int l, int r) {
  int root = ++cnt;
  if (l == r) {
    return root;
  }
  int m = (l + r) >> 1;
  // newly build node
  tr[root].l = build(l, m);
  tr[root].r = build(m + 1, r);
  return root;
} 
int update(int rank, int l, int r, int root) {
  // get a new node since we should genetrate a new same height trace
  int dir = ++cnt;
  tr[dir].l = tr[root].l, tr[dir].r = tr[root].r;
  sum[dir] = sum[root] + 1;
  if (l == r) {
    return dir;
  }
  int m = (l + r) >> 1;
  // the rank is less than the middle, should go to left range and the true left should be newly left
  if (rank <= m) {
    tr[dir].l = update(rank, l, m, tr[root].l);
  } else { // otherwise right range the true right should be newly right
    tr[dir].r = update(rank, m + 1, r, tr[root].r);
  }
  return dir; // dir means the newly added node
}
// query the k-th big number in the list
ll query(int u, int v, int l, int r, int k) {
  // the cur variable means the number of number which is in the range of 
  // if add till now the extra left sum is less than k 
  int m = (l + r) >> 1, cur = sum[tr[v].l] - sum[tr[u].l]; 
  if (l == r) return l;
  if (k <= cur) {
    return query(tr[u].l, tr[v].l, l, m, k);
  } else {
    return query(tr[u].r, tr[v].r, m + 1, r, k - cur);
  }
}
void solve() {
  int n, q, l, r, k;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  memcpy(tmp, arr, sizeof(arr));
  sort(arr + 1, arr + 1 + n);
  int len = unique(tmp + 1, tmp + n + 1) - tmp - 1;
  build(1, len);
  root[0] = build(1, len);
  for (int i = 1; i <= n; ++i) {
    root[i] = update(id(arr[i]), 1, len, root[i - 1]);
  }
  while (q--) {
    cin >> l >> r >> k;
    cout << tmp[query(root[l - 1], root[r], 1, len, k)] << '\n'; // ?
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