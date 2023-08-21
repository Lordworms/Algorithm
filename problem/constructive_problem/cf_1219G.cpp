#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define id(i, j) ((i - 1) * m + j)
void solve() {
  int n, m, id;
  cin >> n >> m;
  vector<int> mp((n + 1) * (m + 1) + 1), tmp(mp);
  vector<ll> X(n + 5), Y(m + 5);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      id = (i - 1) * m + j cin >> mp[id];
      X[i] += mp[id];
      Y[j] += mp[id];
    }
  }
  ll ans = 0;
  // case 1: pick up four rows
  vector<int> xx(n + 1);
  for (int i = 1; i <= n; ++i) {
    xx[i] = X[i];
  }
  sort(xx.begin() + 1, xx.begin() + 1 + n, greater<ll>());
  ans = max(ans, accumulate(xx.begin() + 1, xx.begin() + 5, 0ll));

  // case 2: pick up four columns
  vector<int> yy(m + 1);
  for (int i = 1; i <= m; ++i) {
    yy[i] = Y[i];
  }
  sort(yy.begin() + 1, yy.begin() + 5, greater<ll>());
  ans = max(ans, accumulate(yy.begin() + 1, yy.begin() + 5, 0ll));
  // case 3: one row and three columns
  for (int i = 1; i <= n; ++i) {
    ll max1 = 0, max2 = 0, max3 = 0;
    for (int j = 1; j <= m; ++j) {
      yy[j] = Y[j] - mp[id(i, j)];
      if (yy[j] > max1) {
        max1 = yy[j];
      } else if (yy[j] > max2) {
        max3 = max2;
        max2 = yy[j];
      } else if (yy[j] > max3) {
        max2 = max3;
        max3 = yy[j];
      }
    }
    ans = max(ans, max1 + max2 + max3 + X[i]);
  }
  // case 4: three rows and one column
  for (int j = 1; j <= m; ++j) {
    ll max1 = 0, max2 = 0, max3 = 0;
    for (int i = 1; i <= n; ++i) {
      xx[i] = X[i] - mp[id(i, j)];
      if (xx[i] > max1) {
        max1 = xx[i];
      } else if (xx[i] > max2) {
        max3 = max2;
        max2 = xx[i];
      } else if (xx[i] > max3) {
        max2 = max3;
        max3 = xx[i];
      }
    }
    ans = max(ans, max1 + max2 + max3 + Y[j]);
  }
  // case 5: two rows and two columns
  if (n > m) { // exchange n and m if n is greater than m
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        
      }
    }
  }
  cout << ans << '\n';
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