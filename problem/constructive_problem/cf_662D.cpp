#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  string s;
  cin >> s;
  s = s.substr(4);
  int num = atoi(s.c_str());
  int base = 10, tmp = 0;
  for (int i = 1; i < s.size(); ++i) {
    tmp += base;
    base *= 10;
  }
  while (1989 + tmp > num) {
    num += base;
  }
  cout << num << '\n';
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