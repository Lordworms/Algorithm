#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, m, k, v;
  cin >> n >> m;
  vector sum(n + 1, vector<ll>());
  for (int i = 1; i <= n; ++i) {
    cin >> k;
    sum[i].resize(k + 1);
    for (int j = 1; j <= k; ++j) {
      cin >> v;
      sum[i][j] += sum[i][j - 1] + v;
    }
  }
  vector get(n + 1, vector<ll>());
  for (int i = 1; i <= n; ++i) {
    ll cur_max = 0;
    get[i].resize(sum[i].size());
    for (int j = 1; j < sum[i].size(); ++j) {
      for (int l = 0; l <= j; ++l) {
        int r = sum[i].size() - (j - l) - 1;
        cur_max = max(cur_max, sum[i][l] + sum[i].back() - sum[i][r]);
      }
      get[i][j] = cur_max;
    }
  }
  vector<ll> dp(m + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= 0; --j) {
      for (int k = 1; k < get[i].size(); ++k) {
        if (j >= k) {
          dp[j] = max(dp[j], dp[j - k] + get[i][k]);
        }
      }
    }
  }
  cout << dp[m] << '\n';
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