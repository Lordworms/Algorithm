#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 3e5 + 10;
int a[N];
struct node {
  int l, r, minx, maxx;
};
node tr1[N << 4], tr2[N << 4];

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];

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