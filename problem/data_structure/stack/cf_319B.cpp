#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int ans = 0;
  stack<int> st;
  vector<int> f(n + 1);
  for (int i = 1; i <= n; ++i) {
    int t = 0;
    while (st.size() && a[st.top()] < a[i]) {
      t = max(t, f[st.top()]);
      st.pop();
    }
    if (st.empty()) {
      st.push(i);
      f[i] = 0; // never would be killed
    } else {
      st.push(i);
      f[i] = t + 1;
    }
    ans = max(ans, f[i]);
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