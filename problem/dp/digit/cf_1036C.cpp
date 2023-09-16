#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 20;
ll dp[MAXN][4];
int len;
int p[MAXN];
ll dfs(int pos, int cnt, bool lim) {
  if (pos == -1) return 1;
  if (dp[pos][cnt] != -1 && !lim) return dp[pos][cnt];
  int up = lim ? p[pos] : 9;
  ll res = 0;
  for (int i = 0; i <= up; ++i) {
    if (i && cnt == 3) continue;
    res += dfs(pos - 1, i? cnt + 1 : cnt, lim && i == up); // important to judge the i
  } 
  if (!lim) dp[pos][cnt] = res;
  return res;
}
ll calc(ll x) {
  ll t = x;
  len = 0;
  while (x) {
    p[len++] = x % 10;
    x /= 10;  
  }
  return dfs(len - 1, 0, true);
}
void solve() {
  ll l, r;
  cin >> l >> r;
  cout << calc(r) - calc(l - 1) << '\n'; 
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
  memset(dp, -1, sizeof(dp));
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}