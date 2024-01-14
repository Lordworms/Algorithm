#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> pos, cur;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int cur_mex = 0;
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    cur[a[i]]++;
    while (cur[cur_mex]) cur_mex++;
    // i >= pos[cur_mex] means the current mex is the same as postone
    if (i >= pos[cur_mex]) {
      ans.push_back(cur_mex);
      cur_mex = 0;
      cur.clear();
    }
  }
  cout << ans.size() << '\n';
  for (auto &c : ans) {
    cout << c << ' ';
  }
  cout << '\n';
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