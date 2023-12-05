#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, v;
  cin >> n >> v;
  set<int> s;
  s.insert(v);
  map<int, int> L, R;
  int res = -1;
  for (int i = 1; i <= n - 1; ++i) {
    int x;
    cin >> x;
    auto it = s.upper_bound(x);
    if (it != s.end() && L.count(*it) == 0) { // could add to left
      L[*it] = x;
      res = *it;
    } else {
      --it;
      res = *it;
      R[*it] = x;
    }
    s.insert(x);
    cout << res << ' ';
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