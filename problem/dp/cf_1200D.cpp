#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 4e3 + 10;
int mp[N][N];
void solve() {
  auto add = [&](int x, int y, int w) { mp[max(x, 1)][max(y, 1)] += w; };
  int n, k;
  cin >> n >> k;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = ')' + a[i];
  }
  int ans = 0;
  // get number of shit on rows
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = 0;
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] != 'B') continue;
      if (l == 0) {
        l = j;
      }
      r = j;
    }
    if (r == 0) {
      ++ans;
      continue;
    }
    if (r - l + 1 > k) {
      continue;
    }
    add(i - k + 1, r - k + 1, 1);
    add(i + 1, r - k + 1, -1);
    add(i - k + 1, l + 1, -1);
    add(i + 1, l + 1, 1);
  }
  for (int j = 1; j <= n; ++j) {
    int u = 0, d = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i][j] != 'B') continue;
      if (u == 0) {
        u = i;
      }
      d = i;
    }
    if (d == 0) {
      ++ans;
      continue;
    }
    if (d - u + 1 > k) {
      continue;
    }
    add(d - k + 1, j - k + 1, 1);
    add(d - k + 1, j + 1, -1);
    add(u + 1, j - k + 1, -1);
    add(u + 1, j + 1, 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      mp[i][j] += mp[i - 1][j];
    }
  }
  int cur_max = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      mp[i][j] += mp[i][j - 1];
      cur_max = max(cur_max, mp[i][j]);
    }
  }
  cout << ans + cur_max << '\n';
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