#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int MOD = 1e9 + 7;
ll dp[1005][105][2];
void solve() {
  int n, k, m;
  cin >> n >> k >> MOD;
  vector<ll> fac(n + 1);
  fac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = (fac[i - 1] * 10) % MOD;
  }
  memset(dp, -1, sizeof(dp));
  function<int(int, ll, int)> dfs = [&](int len, ll sum, int f) {
    if (len == n + 1) return f;
    if (~ dp[len][sum][f]) return dp[len][sum][f];
    int st = len == n ? 1 : 0;
    ll res = 0;
    for (int i = st; i <= 9; ++i) {
      res = (res + dfs(len + 1, sum + i * fac[len], f || )) % MOD;
    }
    return dp[len][sum][f] = res;
  };
  cout << dfs(1, 0, 0) << '\n';
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