/*
    h[i] = a * f[i - 2] + b * f[i - 1];
    h[1] = a, h[2] = b;
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;
struct node {
  int l, r;
  ll sum,add1, add2;
};
node tree[MAXN << 2];
ll f[MAXN];
int a[MAXN];
void push_up(int c) {
  tree[c].sum = (tree[c << 1].sum + tree[c << 1 | 1].sum) % MOD;
}
void build(int c, int l, int r) {
  tree[c] = {l, r, 0, 0, 0};
  if (l == r) {
    tree[c].sum = a[l];
    return;
  }
}
void modify() {

}
void solve() {
  int n, m, type;
  cin >> n >> m;
  f[1] = f[2] = 1;
  for (int i = 3; i <= n; ++i) {
    f[i] = f[i - 1] + f[i - 2];
  }
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    cin >> type;
    if (type == 1) {
      
    } else {

    }
  }
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("D:/code/Algorithm/in", "r", stdin);
  freopen("D:/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}