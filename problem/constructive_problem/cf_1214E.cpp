#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct node {
  int u, v, d;
};
void solve() {
  int n;
  cin >> n;
  vector<node> d(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> d[i].d;
    d[i].u = 2 * i;
    d[i].v = 2 * i - 1;
  }
  vector<int> pos(2 * n + 1);
  vector<pair<int, int>> ans;
  int cur = 1;
  sort(d.begin() + 1, d.end(), [&](node a, node b){
    return a.d > b.d;
  });
  int lim = n;
  for (int i = 1; i <= n; ++i) {
    while (pos[cur]) ++cur;
    pos[cur] = d[i].u;
    if (d[i].d + cur - 1 == lim) { // in the end
      pos[cur + d[i].d] = d[i].v;
      ++lim;
    } else {
      ans.push_back({cur + d[i].d - 1, d[i].v});
    }
  }
  for (int i = 1; i <= lim - 1; ++i) {
    ans.push_back({i, pos[i + 1]});
  }
  for (auto &k : ans) {
    cout << pos[k.first] << ' ' << k.second << '\n';
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