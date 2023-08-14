#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
ll gcd(ll a, ll b) {return b? gcd(b, a%b):a;}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<vector<int>> E(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  ll ans = 0;
  function<void(int, int, map<ll, ll>)> dfs = [&](int x, int f,
                                                  map<ll, ll> pre) {
    pre[a[x]]++;
    map<ll, ll> cur;
    for (auto& [p, cnt] : pre) {
      ll g = gcd(a[x], p);
      ans = (ans + g * cnt) % MOD;
      cur[g] += cnt;
    }
    for (int v : E[x]) {
      if (v == f) continue;
      dfs(v, x, cur);
    }
  };
  dfs(1, 0, map<ll, ll>());
  cout << (ans + MOD + MOD) % MOD << '\n';
  return;
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