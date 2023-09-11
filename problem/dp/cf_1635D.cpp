#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n + 1);
  vector<int> b;
  unordered_set<int> st;
  function<bool(int)> check_encounter = [&] (int x) {
    if (!x) {
      return false;
    }
    if (st.count(x)) {
      return true;
    }
    if (x % 4 == 0) {
      return check_encounter(x >> 2);
    }
    if (x & 1) {
      return check_encounter((x - 1) >> 1);
    }
    return false;
  };
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  } 
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; ++i) {
    if (!check_encounter(a[i])) {
      b.push_back(a[i]);
      st.insert(a[i]);
    }
  } 
  vector<ll> f(2e5 + 10);
  for (auto& i : b) {
    int cnt = 0, x = i;
    while(x) {
     ++cnt;
     x >>= 1;
    }
    f[cnt]++;
  }
  ll ans = f[1];
  for (int i = 2; i <= p; ++i) {
    f[i] = (f[i] + f[i - 1] + f[i - 2]) % MOD;
    ans = (ans + f[i]) % MOD;
  }
  cout << ans << '\n';
  return ;
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