#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct Card {
  int l, c;
};
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void solve() {
  int n;
  cin >> n;
  vector<Card> a(n + 1);
  map<int, int> dp;
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i].l;
  for (int i = 1; i <= n; ++i) cin >> a[i].c;
  for (int i = 1; i <= n; ++i) {
    for (auto &k : dp) {
      int g = gcd(a[i].l, k.first);
      if (dp[g] == 0)
        dp[g] = k.second + a[i].c;
      else
        dp[g] = min(dp[g], k.second + a[i].c);
    }
  }
  cout << (dp.count(1) ? dp[1] : -1) << '\n';
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