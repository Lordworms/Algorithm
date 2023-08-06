#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  vector<int> st;
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  // reverse order
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    while (st.size() && a[st.back()] < a[i]) st.pop_back();
    if (st.size()) {
      ans = max(ans, a[st.back()] ^ a[i]);
    }
    st.push_back(i);
  }
  // non-reverse order
  for (int i = n; i >= 1; --i) {
    while (st.size() && a[st.back()] < a[i]) st.pop_back();
    if (st.size()) {
      ans = max(ans, a[st.back()] ^ a[i]);
    }
    st.push_back(i);
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