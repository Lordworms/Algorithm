#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct node {
  int a, id;
};
void solve() {
  int n;
  cin >> n;
  vector<node> a(n + 1);
  vector<int> group(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].a;
    a[i].id = i;
  }
  sort(a.begin() + 1, a.end(), [&](node a, node b) { return a.a < b.a; });
  vector<int> dp(n + 1);
  dp[3] = a[3].a - a[1].a;
  int cur_min = 1e9, cnt = 0;
  for (int i = 4; i <= n; ++i) {
    if (i >= 6 && cur_min > dp[i - 3] - a[i - 2].a) {
      cur_min = dp[i - 3] - a[i - 2].a;  // we generate another team
      cnt = i - 2;  // write down the start of current group
    }
    dp[i] = dp[i - 1] + a[i].a - a[i - 1].a;  // new team
    group[i] = group[i - 1];
    if (dp[i] > cur_min + a[i].a) {
      dp[i] = cur_min + a[i].a;
      group[i] = cnt;
    }
  }
  int ans = 1, cur = group[n];
  vector<int> ans_sets(n + 1);
  for (int i = n; i >= 1; --i) {
    ans_sets[a[i].id] = ans;
    if (i == cur) {
      ans++;
      cur = group[i - 1];
    }
  }
  cout << dp[n] << ' ' << ans << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << ans_sets[i] << " \n"[i == n];
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
  while (T--) {
    solve();
  }
  return 0;
}