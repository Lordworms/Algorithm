#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, len, k;
  cin >> n >> len;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> k;
  int sign = 2;
  ll ans = -1e18;
  while (sign-- > 0) {
    if (sign == 0) {
      for (int i = 1; i <= n; ++i) a[i] = -a[i];
    }   
    multiset<int> xm, ym;   
    ll sum = 0;        
    for (int i = 1; i <= n; ++i) {
      // deal with the current a[i]
      if (a[i] >= 0) {
        sum += a[i];    
      } else if (xm.size() < k) {
        sum += -a[i];
        xm.insert(a[i]);
      } else if (xm.size() && a[i] < *(--xm.end())) {
        xm.insert(a[i]);
        ll v = *(--xm.end());
        xm.erase(xm.find(v));// do not forget!!! important
        sum -= -v, sum += v;
        sum += -a[i];
        ym.insert(v);
      } else {
        sum += a[i];
        ym.insert(a[i]);
      }
      // deal with previous one since the length is len
      int bef = i - len;
      if (bef >= 1) {
        if (a[bef] >= 0) {
          sum -= a[bef];
        } else if (xm.find(a[bef]) != xm.end()) {
          sum -= -a[bef];
          xm.erase(xm.find(a[bef])); 
          if (!ym.empty()) {
            ll v = *(ym.begin());
            sum -= 2 * v;
            xm.insert(v);
            ym.erase(ym.find(v));// important
          }
        } else if (ym.find(a[bef]) != ym.end()) {
          sum -= a[bef];
          ym.erase(ym.find(a[bef]));
        }
      }
      if (bef >= 0) ans = max(ans, sum);
    }
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