#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 16;
int dp[N][N][N], dig[N], len;
int sum[N];
void add(ll x) {
  ll tmp = x;
  while (tmp) {
    dig[++len] = tmp % 10;
    tmp /= 10;
  }
}
// flag set to 1 means we could precalculate
ll dfs(int pos, int pre, int sum, int flag) {
  if (pos == 0) return pre == sum;
  if (flag && dp[pos][pre][sum] != -1) return dp[pos][pre][sum];
  int lim = flag? 9 : dig[pos];
  ll ans = 0;
  for (int i = 0; i <= lim; ++i) {
    ans = (ans + dfs(pos - 1, pre + (i == 4 || i == 7), sum, flag || i < lim));
  }
  if (flag) dp[pos][pre][sum] = ans;
  return ans;
}
ll calc(int pos, int rem) {
  if (pos == 7) return 1;
  ll ans = 0;
  for (int i = 0; i <= rem; ++i) {
    if (sum[i]) {
      sum[i]--;
      ans = (ans + ((sum[i] + 1) * calc(pos + 1, rem - i)) % MOD) % MOD;
      sum[i]++;
    }
  }
  return ans;
}
void solve() {
  memset(dp, -1, sizeof(dp));
  ll m;
  cin >> m;
  add(m);
  for (int i = 0; i <= len; ++i) {
    sum[i] = dfs(len, 0, i, 0);
  }
  // minus one means we could not pick up all contains 0 lucky number
  sum[0]--;
  ll ans = 0;
  for (int i = 1; i <= len; ++i) {
    ans = (ans + sum[i] * calc(1, i - 1)) % MOD;
  }
  cout << ans << '\n';
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