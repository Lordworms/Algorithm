#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, p;
  cin >> n >> p;
  vector<ll> f(p + 1), sum(p + 1);
  vector<int> a(n + 1);
  unordered_set<int> st;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  } 
  sort(a.begin() + 1, a.end());
  auto check = [&](int x) {
    
  };
  for (int &x : a) {

  }
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