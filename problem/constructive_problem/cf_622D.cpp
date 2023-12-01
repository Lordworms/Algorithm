#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n;
  cin >> n;
  vector<int> ans(2 * n + 1);
  int l = 1, r = n, cnt = 1;
  while (l <= r) {
    ans[l++] = ans[r--] = cnt;
    cnt += 2;
  }
  l = n + 1, r = 2 * n - 1, cnt = 2;
  while (l <= r) {
    ans[l++] = ans[r--] = cnt;
    cnt += 2;
  }
  for (int i = 1; i <= 2 * n; ++i) {
    cout << (ans[i] ? ans[i] : n) << " \n" [i == 2 * n];
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