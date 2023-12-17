#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
#define deg(x) (E[x].size())
ll quick_pow(ll base, ll exp, int MOD) {
  ll ans = 1;
  while (exp) {
    if (exp & 1) ans = ans * base % MOD;
    base = base * base % MOD;
    exp >>= 1;
  }
  return ans % MOD;
}
ll inv(ll x) { return quick_pow(x, MOD - 2, MOD); }
void solve() {
  int n, s, t;
  cin >> n >> s >> t;
  vector<vector<int>> E(n + 1);
  vector<int> vis(n + 1), has(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<ll> dp(n + 1);
  function<void(int)> dfs1 = [&](int x) {
    vis[x] = 1;
    for (int &v : E[x]) {
      if (vis[v]) continue;
      dfs1(v);
      if (has[v]) continue;
      dp[v] = (v == t? 0 : (dp[v] * inv(deg(v))) + 1) % MOD * deg(v) % MOD;
      has[v] = 1;
    }
    if (x == t) {
      dp[x] = 1;
      has[x] = 1;
    }
  };
  function<void(int)> dfs2 = [&](int x) {
    vis[x] = 1;
    for (auto &v : E[x]) {
      if (vis[v]) continue;
      if (has[x] && x != t && !has[v]) {
        dp[v] = dp[x] * inv(deg(x)) % MOD * deg(v) % MOD;
        has[v] = 1;
      }   
      dfs2(v); 
    }
  };
  dfs1(s);
  fill(vis.begin(), vis.end(), 0);
  dfs2(s);
  for (int i = 1; i <= n; ++i) {
    cout << dp[i] << " \n" [i == n];
  }
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