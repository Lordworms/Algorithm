#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
using pii = pair<int, int>;
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
  int n, m;
  cin >> n >> m;
  vector<int> p(n + 1), id(n + 1);
  vector<vector<int>> group(n + 1);
  fenwick tr;
  for (int i = 1; i <= n; ++i)  {
    cin >> p[i];
    id[p[i]] = i;
  }
  int x, y;
  for (int i = 1; i <= n; ++i) {
    for (int j = i ; j <= n; j += i) {
      x = id[i], y = id[j];
      if (y > x) {
        swap(x, y);
      }
      group[x].push_back(y);
    }
  }// group[i] stores the actual factor which is less than i
  int l, r;
  vector<vector<pii>> query(n + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r;
    query[r].push_back({l, i}); // query[i] stores the actual query left ptr and the is of the query
  }
  vector<int> ans(m + 1);
  for (int i = 1; i <= n; ++i) {
    for (int v : group[i]) {
      tr.add(v, 1); // the shit we are adding could be counted as the paris between [1, i]
    }
    for (auto& [l, now] : query[i]) {
      ans[now] = tr.get(i) - tr.get(l - 1); // now we are calculating the pair between [l, i] which is like this
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << " \n";
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