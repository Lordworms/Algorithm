#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 3e5 + 10;
const int M = 5e5 + 10;
int status[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= 3 * n; ++i) status[i] = 0;
  vector<int> ans;
  auto calc = [&]() {
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      if (!status[u] && !status[v]) {
        ans.push_back(i);
        status[u] = status[v] = 1;
      }
    }
    if (ans.size() >= n) {
      return true;
    }
    ans.clear();
    for (int i = 1; i <= 3 * n; ++i) {
      if (!status[i]) {
        ans.push_back(i);
      }
    }
    return false;
  };
  if (calc()) {
    cout << "Matching \n";
  } else {
    cout << "IndSet"
         << "\n";
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}