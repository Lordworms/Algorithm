#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, N;
  cin >> n;
  N = 2 * n;
  vector<int> blocks;
  vector<int> c(2 * n + 1);
  for (int i = 1; i <= N; ++i) cin >> c[i];
  int maxx = -1, cnt = 0;
  for (int i = 1; i <= N; ++i) {
    if (i == 1 || c[i] < maxx) {
      ++cnt;
      maxx = max(maxx, c[i]);
    } else {
      blocks.push_back(cnt);
      cnt = 1;
      maxx = c[i];
    }
  }
  blocks.push_back(cnt);
  vector dp(blocks.size() + 1, vector<int>(n + 1, 0)), take(dp);
  dp[0][0] = 1;

  for (int i = 1; i <= blocks.size(); ++i) {
    for (int v = 0; v <= n; ++v) {
      dp[i][v] = dp[i - 1][v];
      if (v >= blocks[i - 1] && dp[i - 1][v - blocks[i - 1]]) {
        dp[i][v] = take[i][v] = 1;
      }
    }
  }
  if (!dp[blocks.size()][n]) {
    cout << -1 << '\n';
    return;
  }
  vector<int> a, b;
  int len = n, cur = n << 1;
  for (int i = blocks.size(); i > 0; --i) {
    if (take[i][len]) {
      for (int j = cur; j > cur - blocks[i - 1]; --j) {
        a.push_back(c[j]);  
      }
      len -= blocks[i - 1];
      cur -= blocks[i - 1];
    } else {
      for (int j = cur; j > cur - blocks[i - 1]; --j) {
        b.push_back(c[j]);  
      }
      cur -= blocks[i - 1];
    }
  }
  reverse(a.begin(), a.end());
  for (auto &c : a) {
    cout << c << ' ';
  }
  cout << '\n';
  reverse(b.begin(), b.end());
  for (auto &c : b) {
    cout << c << ' ';
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