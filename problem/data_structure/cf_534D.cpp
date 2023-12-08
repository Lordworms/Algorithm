#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> s(n + 1);
  int x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    a[i] = x;
    s[x].push_back(i);
  }
  vector<int> ans(n + 1);
  int cnt = 0, cur = 0, top = 0;
  while (cnt < n) {
    if (!s[cur].empty()) {
      ans[++top] = s[cur].back();
      s[cur].pop_back();
      ++cur;
      ++cnt;
    } else {
      if (cur >= 3) {
        cur -= 3;
      } else {
        cout << "Impossible" << '\n';
        return;
      }
    }
  }
  cout << "Possible" << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n" [i == n];
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