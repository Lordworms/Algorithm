#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 210;
const int N = 2e5 + 10;
int cnt[N][MAXN];
int a[MAXN];
void solve() {
  int n, ans = 0;
  cin >> n;
  vector<int> pos[MAXN];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= 200; ++j) {
        cnt[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i - 1]));
    cnt[i][a[i]]++;
    pos[a[i]].push_back(i);
  }
  for (int i = 1; i <= 200; ++i) {
    int sz = pos[i].size();
    ans = max(ans, sz);
    for (int j = 0; j < sz / 2; ++j) {
      int l = pos[i][j], r = pos[i][sz - j - 1] - 1;
      for (int k = 1; k <= 200; ++k) {
        int mid = cnt[r][k] - cnt[l][k];
        ans = max(ans, (j + 1) * 2 + mid);
      }
    }
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt", "r", stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt", "w", stdout);
#endif
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}