#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n + 1);
  vector<int> deg(n + 1);
  for (int i = 1 ; i <= n; ++i) {
    int k;
    cin >> k;
    deg[i] = k;
    while (k--) {
      int x;
      cin >> x;
      E[x].push_back(i);
    }
  } 
  deque<int> q;
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) {
      q.push_back(i);
      dp[i] = 1;
    }
  }
  while (!q.empty()) {
    auto cur = q.front();
    q.pop_front();
    for (int &v : E[cur]) {
      --deg[v];
      if (!deg[v]) {
        q.push_back(v);
        if (cur > v) { // could read in one simulation
          dp[v] = max(dp[cur] + 1, dp[v]);
        } else {
          dp[v] = max(dp[v], dp[cur]);
        }
      }
    }
  }
  bool have_answer = true;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (deg[i]) {
      have_answer = false;
      break;
    }
    ans = max(ans, dp[i]);
  }
  if (have_answer) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}