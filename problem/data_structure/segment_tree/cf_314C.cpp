#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 1e6 + 10;
#define int ll
#define lowbit(x) (x & (-x))
ll tree[N];
int n;
void add(int x, int v) {
  while (x < N) {
    tree[x] = (tree[x] + v) % MOD;
    x += lowbit(x);
  }
}
int sum(int x) {
  int res = 0;
  while (x) {
    res = (res + tree[x]) % MOD;
    x -= lowbit(x);
  }
  return res % MOD;
}
void solve() {
  cin >> n;
  vector<int> a(n + 1), pre(N), dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1ll * ((sum(a[i]) + 1) * a[i]) % MOD;
    // the previous one j could be updated by i either
    if (pre[a[i]]) {
      add(a[i], -dp[pre[a[i]]]);
      dp[pre[a[i]]] = 0;
    }
    pre[a[i]] = i;
    add(a[i], dp[i]);
  }
  ll ans = 0;
  for (int i = n; i >= 1; --i) {
    ans = (ans + dp[i]) % MOD;
  }
  cout << (ans + MOD) % MOD << '\n';
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