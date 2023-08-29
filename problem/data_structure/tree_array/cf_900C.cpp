#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 1e5 + 10;
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
  int n;
  cin >> n;
  vector<int> p(n + 1);
  fenwick tr;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  ll ans = -1, ans_i = 1;
  int cur_max = -1;
  vector<int> cnt(n + 1);
  for (int i = 1; i <= n; ++i) {
    cur_max = max(cur_max, p[i]);
    int cur_num = tr.get(p[i]);
    if (cur_num == i - 2) {
      cnt[cur_max]++;
    } else if (cur_num == i - 1){
      cnt[cur_max]--;
    }
    tr.add(p[i], 1);
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > ans) {
      ans = cnt[i];
      ans_i = i;
    }
  }
  cout << ans_i << '\n';
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