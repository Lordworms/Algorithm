#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int lim = sqrt(2 * n);
  int three = 0, seven = 0;
  for (int i = lim; i <= 2 * n; ++i) {
    if (i * (i - 1) <= 2 * n) {
      three = i;
      seven = n - (i * (i - 1) / 2);
    } else {
      break;
    }
  }
  cout << "133"; // using 3 and 7 one by one in order to make the number controlled C(three, 2) + seven  == n
  for (int i = 0; i < seven; ++i) {
    cout << "7";
  }
  for (int i = 0; i < three - 2; ++i) {
    cout << "3";
  }
  cout << "7";
  cout << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}