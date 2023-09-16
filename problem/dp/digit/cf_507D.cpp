/*
  https://www.luogu.com.cn/blog/virus2017/shuweidp
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int MOD = 1e9 + 7;
const int N = 1e3 + 10;
const int K = 102;
int n, k;
ll dp[N][K][2];
ll n_10[N];
ll dfs(int pos, int rem, int have) {
  if (pos > n) {
    return have;
  }   
  if (dp[pos][rem][have] != -1) return dp[pos][rem][have];
  ll res = 0;
  for (int i = (pos == n? 1 : 0); i <= 9; ++i) {
    res += dfs(pos + 1, (rem + n_10[pos] * i) % k, have || ((rem + n_10[pos] * i) % k == 0 && i));
  }
  return dp[pos][rem][have] = res % MOD;
}
void solve() {
  cin >> n >> k >> MOD;
  n_10[1] = 1;
  memset(dp, -1, sizeof(dp));
  for (int i = 2; i <= n; ++i) {
    n_10[i] = (n_10[i - 1] * 10) % k;
  } 
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