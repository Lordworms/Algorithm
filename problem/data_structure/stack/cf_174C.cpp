#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
using pii = pair<int, int>;
void solve() {
  int n; cin >> n;
  vector<int> st, a(n + 1);
  vector<pii> ans;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] < a[i - 1]) {
      for (int cur = a[i]; cur < a[i - 1]; ++cur) {
        ans.push_back({st.back(), i - 1}); // we subtract from the single stack
        st.pop_back();
      }
    } else {
      for (int cur = a[i] - 1; cur >= a[i - 1]; --cur) {
       // we enqueu the current one since we need to subtract in the future
        st.push_back(i);
      }
    }
  }
  while (st.size()) {
    ans.push_back({st.back(), n});
    st.pop_back();
  }
  cout << ans.size() << '\n';
  for (auto &r : ans) {
    cout << r.first << ' ' << r.second << '\n';
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
  while (T--) {
    solve();
  }
  return 0;
}