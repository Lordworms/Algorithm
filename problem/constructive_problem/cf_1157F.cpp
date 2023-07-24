#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(N);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }
  int st = 0, ed = 0, ans = 1, cur_len = 0, ans_st = 0;
  for (int i = 1; i < N; ++i) {
    if (st && a[i] < 2) {
      cur_len += a[i];
      if (cur_len >= ans) {
        ans = cur_len;
        ans_st = st;
        ed = i;
      }
      st = 0;
      cur_len = 0;
    } else if (st && a[i] >= 2) {
      cur_len += a[i];
    }
    if (!st && a[i]) {
      st = i;
      cur_len += a[i];
    }
  }
  cout << ans << '\n';
  for (int i = ans_st; i <= ed; ++i) {
    for (int j = 1; j < a[i]; ++j) {
      cout << i << ' ';
    }
  }
  for (int i = ed; i >= ans_st; --i) {
    if (a[i]) {
      cout << i << ' ';
    }
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