#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> x(k + 1), c(k + 1);
  for (int i = 1; i <= k; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i <= k; ++i) {
    cin >> c[i];
  }
  /*
    for k == 1, we could always achieve P in [3, n] by  aaaabcabcabc since adding the same char is the same shit
    if c[i] - c[i - 1] > x[i] - x[i - 1] then we could not achieve it since the increase amount is always less than the length increasment
  */
  if (c[1] > x[1]) {
    cout << "NO" << '\n';
    return;
  }
  string ans;
  for (int i = 1; i <= c[1] - 3; ++i) {
    ans.push_back('a');
  }
  char cur = 'a';
  for (int i = c[1] - 2; i <= x[1]; ++i) {
    ans.push_back(cur++);
    if (cur == 'd') cur = 'a';
  }
  for (int i = 2; i <= k; ++i) {
    int dc = c[i] - c[i - 1], dx = x[i] - x[i - 1];
    if (dc > dx) {
      cout << "NO" << '\n';
      return;
    }
    for (int j = 1; j <= dc; ++j) {
      ans.push_back('b' + i);
    }
    for (int j = 1; j <= dx - dc; ++j) {
      ans.push_back(cur++);
      if (cur == 'd') cur = 'a';
    }
  }
  cout << "YES" << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}