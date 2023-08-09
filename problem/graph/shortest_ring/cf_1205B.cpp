#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector<ll> a;
  for (int i = 1;i <= n; ++i) {
    ll x;
    cin >> x;
    if (x) {
      a.push_back(x);
    }
  } 

  if (a.size() > 128) {
    cout << 3 << '\n';
    return;
  }
  n = a.size();
  // do floyed
  vector dis(n, vector<ll>(n)), weight(dis);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((a[i] & a[j]) != 0 && i != j) {
        dis[i][j] = weight[i][j] = 1;
      } else {
        dis[i][j] = weight[i][j] = INF;
      }
    }
  }
  ll ans = INF;
  /*
    using floyed to get shortest ring
  */
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || j == k || i == k )continue;
        ans = min(ans, dis[i][j] + weight[i][k] + weight[k][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)continue;
        dis[i][j] = min (dis[i][k] + dis[k][j], dis[i][j]);
      }
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n'; 
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in","r",stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out","w",stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}