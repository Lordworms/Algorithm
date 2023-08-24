#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 30;
struct fenwick {
  ll PartialSum[MAXN];
  fenwick() {
    for (int i = 0; i < MAXN; i++) PartialSum[i] = 0;
  }
  inline void add(ll index, ll increase) {
    while (index < MAXN) {
      PartialSum[index] += increase;
      index += index & -index;
    }
  }
  inline ll get(int index) {
    ll sum = 0;
    while (index) {
      sum += PartialSum[index];
      index -= index & -index;
    }
    return sum;
  }
};
void solve() {
  int n, k;
  ll x;
  cin >> n >> k;
  char c;
  vector<ll> fac(MAXN);
  vector<int> vis(n + 1);
  fac[0] = fac[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  fenwick tr;
  vector<int> a(n + 1);
   while (k--) {
    cin >> c;
    switch (c) {
      case 'P': {
        fill(vis.begin(), vis.end(), 0);
        cin >> x;
        x--;
        for (int i = 1; i <= n; ++i) {
          ll tmp = x / fac[n - i];
          for (int j = 1; j <= n; ++j) {
            if (!vis[j]) {
              if (!tmp--) {
                vis[j] = 1;
                cout << j << ' ';
                break;
              }
            }
          }
          x %= fac[n - i];
        }
        cout << '\n';
        break;
      }
      case 'Q': {
        for (int i = 1; i <= n; ++i) {
          tr.add(i, 1);  
        }
        ll ans = 1;
        for (int i = 1; i <= n; ++i) {
          int a;
          cin >> a;
          tr.add(a, -1);
          ans += tr.get(a) * fac[n - i]; 
        }
        cout << ans << '\n';
        break;
      }
      default: {
        break;
      }
    }
  }
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