#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define int ll
void solve() {
  int n, d, m, x;
  cin >> n >> d >> m;
  vector<int> big, small;
  big.push_back(0);
  small.push_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> x; 
    if (x > m) {
      big.push_back(x);
    } else {
      small.push_back(x);
    }
  }
  sort(big.begin() + 1, big.end(), greater<int>());
  sort(small.begin() + 1, small.end(), greater<int>());
  vector<int> sum(small.size());
  for (int i = 1; i < sum.size(); ++i) {
    sum[i] = sum[i - 1] + small[i];
  }
  int ans = sum.back();
  int cur = 0;
  for (int i = 1; i < big.size(); ++i) {
    cur += big[i];
    int consumed = (i - 1) * (d + 1) + 1;
    int left = n - consumed;
    if (consumed > n) {
        break;
    }
    left = min(left, (int)sum.size() - 1);// important since we could not determin which prefix to use
    ans = max(ans, sum[left] + cur);
  }
  cout << ans << '\n';
  return;
}
signed main() {
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