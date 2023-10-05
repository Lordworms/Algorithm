#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 4e5+10; 
#define int ll
const int INF = 0x3f3f3f3f;
struct node {
  ll maxx, minx;
  int l, r;
};
node tree[MAXN << 2];
int arr[MAXN], pos[MAXN];
void build (int l, int r, int c) {
  tree[c].l = l;
  tree[c].r = r;
  if (l == r) {
    tree[c].maxx = arr[l];
    tree[c].minx = arr[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, c << 1);
  build(mid + 1, r, c << 1 | 1);
  tree[c].maxx = max(tree[c << 1].maxx, tree[c << 1 | 1].maxx);
  tree[c].minx = min(tree[c << 1].minx, tree[c << 1 | 1].minx);
}
ll queryMax(int l, int r, int c) {
  if (tree[c].l >= l && tree[c].r <= r) {
    return tree[c].maxx;
  }
  int mid = (tree[c].l + tree[c].r) >> 1;
  ll ans = -1;
  if (l <= mid) {
    ans = max(ans, queryMax(l, r, c << 1));
  } 
  if (r > mid) {
    ans = max(ans, queryMax(l, r, c << 1 | 1));
  }
  return ans;
}
ll queryMin(int l, int r, int c) {
  if (tree[c].l >= l && tree[c].r <= r) {
    return tree[c].minx;
  }
  int mid = (tree[c].l + tree[c].r) >> 1;
  ll ans = 1e17;
  if (l <= mid) {
    ans = min(ans, queryMin(l, r, c << 1));
  } 
  if (r > mid) {
    ans = min(ans, queryMin(l, r, c << 1 | 1));
  }  
  return ans;
}
int cal(int l, int r) {
  if (l + 1 == r) {
    return 1;
  }
  if (l >= r) {
    return 0;
  }
  ll l1 = pos[queryMin(l, r, 1)];
  ll r1 = pos[queryMax(l, r, 1)];
  if (l1 > r1) {
    swap(l1, r1);
  }
  return 1 + cal(l, l1) + cal(r1, r);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  build(1, n, 1);
  cout << cal(1, n) << '\n';
  return ;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}