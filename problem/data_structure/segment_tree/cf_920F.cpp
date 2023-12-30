#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 3e5 + 10;
const int LIM = 1e6;
#define int ll
struct Node {
  int l, r, maxv, sumv;
};
Node tr[N << 2];
int cnt[LIM + 10], arr[N];
void push_up(int c) {
  tr[c].maxv = max(tr[c << 1].maxv, tr[c << 1 | 1].maxv);
  tr[c].sumv = tr[c << 1].sumv + tr[c << 1 | 1].sumv;
}
void build(int c, int l, int r) {
  tr[c] = {l, r, 0, 0};
  if (l == r) {
    tr[c].maxv = tr[c].sumv = arr[l]; // stupid ass stupid ass stupid ass stupid ass stupid ass stupid ass stupid ass stupid ass stupid ass stupid ass stupid ass
    return;
  }
  int m = (l + r) >> 1;
  build(c << 1, l, m);
  build(c << 1 | 1, m + 1, r);
  push_up(c);
}
void update(int c, int l, int r) {
  if (tr[c].maxv <= 2) return;
  if (tr[c].l == tr[c].r) {
    arr[tr[c].l] = cnt[arr[tr[c].l]];
    tr[c].maxv = tr[c].sumv = arr[tr[c].l];
    return;  
  }      
  int m = (tr[c].l + tr[c].r) >> 1;
  if (l <= m) {
    update(c << 1, l, r);
  } 
  if (r > m) {
    update(c << 1 | 1, l, r);
  }
  push_up(c);
}
int query(int c, int l, int r) {
  if (tr[c].l >= l && tr[c].r <= r) {
    return tr[c].sumv;
  }    
  int m = (tr[c].l + tr[c].r) >> 1;
  int ans = 0;
  if (m >= l) {
    ans += query(c << 1, l, r);
  } 
  if (r > m) {
    ans += query(c << 1 | 1, l, r);
  }
  return ans;
}
void init() {
  for (int i = 2; i <= LIM; ++i) {
    for (int j = i; j <= LIM; j += i) {
      ++cnt[j];
    }
    ++cnt[i];
  }  
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  init();
  build(1, 1, n);
  int type, x, y;
  while (m--) {
    cin >> type >> x >> y;
    if (type == 1) {
      update(1, x, y);
    } else {
      cout << query(1, x, y) << '\n';
    }
  }
  return;
}
signed main() {
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