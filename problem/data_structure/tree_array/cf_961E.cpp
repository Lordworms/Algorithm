#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 2e5 + 10;
ll tr[N << 2];
int n;
#define lowbit(x) (x & -x)
void add(int x, int v) {
  while (x <= n) {
    tr[x] += v;
    x += lowbit(x);
  }
}
ll sum(int x) {
  ll res = 0;
  while (x) {
    res += tr[x];
    x -= lowbit(x);   
  }
  return res;
}
void solve() {
  cin >> n;
  vector<int> a(n + 1);
  ll ans = 0;
  vector<vector<int>> Q(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = min(a[i], n);
    // a[j] >= i
    Q[min(a[i], i - 1)].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    add(a[i], 1);
    for (auto &k : Q[i]) {
      // a[i] >= j
      ans += sum(n) - sum(k - 1);
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