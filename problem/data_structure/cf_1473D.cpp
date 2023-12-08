#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> lim(n + 2);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      cur++; 
    } else  {
      cur--;
    }
    lim[i + 1] = cur;
  }
  vector<int> lmin(n + 1, INF), lmax(n + 1, 0), rmin(n + 1, INF), rmax(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    lmin[i] = min(lmin[i - 1], lim[i]);
    lmax[i] = max(lmax[i - 1], lim[i]);
  }
  for (int i = n; i >= 1; --i) {
    rmin[i] = min(rmin[i + 1], lim[i]);
    rmax[i] = max(rmax[i + 1], lim[i]);
  }
  int l, r;
  while (m--) {
    cin >> l >> r;
    if (r == n) {
      cout << lmax[l] - lmin[l] << '\n';
      continue;
    }
    int up_flow = 
    int down_flow = 
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
  int T = 2;
  while (T--) {
    solve();
  }
  return 0;
}