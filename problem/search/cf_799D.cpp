#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 1e5 + 10;
const int NN = 38;
ll dp[NN][N];
void solve() {
  int a, b, h, w, n;
  cin >> a >> b >> h >> w >> n;
  vector<ll> times(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> times[i];
  }
  // dp[i][j] means the maximum w when the height reaches j
  function<int(ll, ll, ll, ll)> get = [&] (ll a, ll b, ll h, ll w) {
    memset(dp, -1, sizeof(dp));
    int ans = -1;
    dp[0][min(a, h)] = min(b, w);
    for (int i = 1; i <= std::min(35, n); ++i) {
      for (int j = 1; j <= a; ++j) {
        if (dp[i - 1][j] == -1) continue;
        ll maxx = min(a, j * times[i]);
        ll maxy = min(dp[i - 1][j] * times[i], b);
        // use the times[i] on width
        dp[i][j] = max(dp[i][j], maxy);
        // use the times or not
        dp[i][maxx] = max(dp[i][maxx], dp[i - 1][j]);
      }    
    }
    for (int i = 1; i < 36; ++i) {
      if (dp[i][a] >= b) {
        ans = i;
        break;  
      }
    }
    return ans;
  };
  if (h >= a && w >= b || h >= b && w >= a) {
    cout << 0 << '\n';
    return;
  }
  sort(times.begin() + 1, times.end(), greater<ll>());
  int ans = min(get(a, b, w, h), get(a, b, h, w));
  if (ans == -1) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
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