#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
struct Book {
  int w, t;
};
void solve() {
  int n;
  cin >> n;
  vector<Book> a(n + 1);
  int sumw = 0, sumt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].t >> a[i].w;
    sumw += a[i].w;
    sumt += a[i].t;
  }
  vector<int> dp(sumt + 1, -INF);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int v = sumt; v >= a[i].t; --v) {
      dp[v] = max(dp[v], dp[v - a[i].t] + a[i].w);
    }
  }
  for (int i = 1; i <= sumt; ++i) {
    if (dp[i] >= sumw - i) {
      cout << i << '\n';
      return;
    }
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