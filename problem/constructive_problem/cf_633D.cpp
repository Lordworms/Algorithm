#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  map<int, int> mp;
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a.begin() + 1, a.end());
  // important since we starts from zero
  int ans = mp[0];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j || (a[i] == a[j] && a[i] == 0)) {
        continue;
      }
      int a1 = a[i], a2 = a[j];
      int cur_len = 2;
      vector<int> cur;
      --mp[a1];
      --mp[a2];
      cur.push_back(a1);
      cur.push_back(a2);
      while (mp[a1 + a2]) {
        --mp[a1 + a2];
        cur.push_back(a1 + a2);
        swap(a1, a2);
        a2 = a1 + a2;
        ++cur_len;
      }
      ans = max(ans, cur_len);
      for (int &v : cur) {
        mp[v]++;
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
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}