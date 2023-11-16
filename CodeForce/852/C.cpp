#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 1, r = n, L = 1, R = n;
  while (l <= r) {
    if (a[l] == L) {
      ++L, ++l;
    } else if (a[r] == L) {
      ++L, --r;
    } else if (a[l] == R) {
      --R, ++l;
    } else if (a[r] == R) {
      --R, --r;
    } else {
      break;
    }
  }
  if (l <= r) {
    cout << l << ' ' << r << '\n';
  } else  {
    cout << -1 << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}