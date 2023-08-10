#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 100;
void solve() {
  vector<int> a(N + 1), b(a);
  for (int i = 1; i <= N; ++i) {
    a[i] = i;
    b[i] = (i << 7);
  } 
  cout << "? ";
  for (int i = 1; i <= N; ++i) {
    cout << a[i] << " \n" [i == N];
  }
  cout.flush();
  int c;
  cin >> c;
  cout << "? ";
  for (int i = 1; i <= N; ++i) {
    cout << b[i] << " \n" [i == N];
  }
  cout.flush();
  int d;
  cin >> d;
  int B = (c ^ d) >> 7;
  cout <<"! "<<((B << 7) ^ d) << '\n';
  return ;
}
int main() {
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