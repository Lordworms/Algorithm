#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 3e5 + 10;
const int LIM = 1e6 + 10;
struct Node {
  int l, r, maxv, sumv;
};
Node tr[N << 2];
int cnt[LIM];
void push_up(int c) {
  tr[c].maxv = max(tr[c << 1].maxv, tr[c << 1 | 1].maxv);
  tr[c].sumv = tr[c << 1].sumv + tr[c << 1 | 1].sumv;
}
void build(int c, int l, int r) {
  tr[c] = {l, r, 0};
  if (l == r) {
    cin >> tr[c].sumv;
    return;
  }
  int m = (l + r) >> 1;
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
  push_up(c);
}
void update() {
    
}
void init() {
  
}
void solve() {
  int n, m;
  cin >> n >> m;

  return;
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