#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
struct fenwick {
  ll PartialSum[MAXN];
  fenwick() {
    for (int i = 0; i < MAXN; i++) PartialSum[i] = 0;
  }
  inline void add(ll index, ll increase) {
    while (index < MAXN) {
      PartialSum[index] += increase;
      index += index & -index;
    }
  }
  inline ll get(int index) {
    ll sum = 0;
    while (index) {
      sum += PartialSum[index];
      index -= index & -index;
    }
    return sum;
  }
};
void solve() {
  int n, k, ans = 0;
  cin >> n >> k;
  fenwick tr;
  vector<int> h(n + 1);
  int maxx = INT_MIN, minx = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    maxx = max(maxx, h[i]);
    minx = min(minx, h[i]);
    tr.add(1, 1);
    tr.add(h[i] + 1, -1);
  } 
  if (maxx == minx) {
    cout << 0 << '\n';
    return;
  }
  ll sum = 0;
  bool flag = true;
  for (int i = maxx; i >= minx; --i) {
    auto cur = tr.get(i); //how many shits is greater or equal than height i
    if (cur + sum > k) {
      ans++;
      sum = cur;
      flag = false;
    } else {// other wise one shot to make them equal
      sum += cur;
      flag = true;
    }
  }
  if (flag) {
    ++ans;
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