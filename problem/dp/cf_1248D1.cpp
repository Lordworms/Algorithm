#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = ')' + s;
  vector<int> cnt(n + 1);
  auto calc = [&]() {
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 1; i <= n; ++i) {
      cnt[i] = cnt[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    if (cnt[n]) {
      return 0;
    }
    int cur_min = *min_element(cnt.begin() + 1, cnt.end()), cur_cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] == cur_min) {
        ++cur_cnt;
      }
    }
    return cur_cnt;
  };
  int l = 0, r = l, ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      swap(s[i], s[j]);
      int res = calc();
      if (res >= ans) {
        ans = res;
        l = i;
        r = j;
      }
      swap(s[i], s[j]);
    }
  }
  cout << ans << '\n' << l << ' ' << r << '\n';
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