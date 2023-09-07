#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void solve() {
  ll bi, bd, bl, ci, cd, cl;
  cin >> bi >> bd >> bl >> ci >> cd >> cl;
  ll endb = bi + (bl - 1) * bd;
  ll endc = ci + (cl - 1) * cd;
  // cases when no answer could show off
  if (cd % bd != 0    // case 1: the difference could not divided entirely
      || endc > endb  // case 2: no intersection
      || ci < bi      // case 2: no intersection
      || abs(bi - ci) % bd != 0  // case 3: similar to case 2
  ) {
    cout << 0 << '\n';
    return;
  }
  // cases when there are infinite answer
  if (ci - cd <
          bi ||  // case 1: when leftesth - 1 element is less than the initial
                 // element of b, then a could starts in any position
      endc + cd > endb  // case 2: same as case1
  ) {
    cout << -1 << '\n';
    return;
  }
  // cases when there are finite answer
  vector<int> fac;
  int i;
  for (i = 2; i * i < cd; ++i) {
    if (cd % i == 0) {  // all factors
      fac.push_back(i);
      fac.push_back(cd / i);
    }
  }
  if (i * i == cd) {
    fac.push_back(i);
  }
  ll ans = 1;
  for (auto& f : fac) {
    int g = gcd(f, bd);
    int lcm = f * bd / g;
    if (lcm != cd) {  // we have to let the lcm equal to cd otherwise it is not
                      // possible to intersect
      continue;
    }
    ans = (ans + 1ll * cd / f * cd / f) % MOD;
  }
  if (cd == bd) {
    ans = (ans + 1ll * bd * bd) % MOD;
  }
  cout << ans << '\n';
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