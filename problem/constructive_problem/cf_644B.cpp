#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
#define int ll
struct Query {
  int id, t, d, finish;
};
void solve() {
  int n, b;
  cin >> n >> b;
  vector<Query> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].t >> a[i].d;
    a[i].id = i;
  }
  sort(a.begin() + 1, a.end(), [&](Query a, Query b) {
    return a.t < b.t;
  });
  queue<Query*> q;
  int should_finish = 0;
  bool is_busy = false;
  for (int i = 1; i <= n; ++i) {
    if (!is_busy) {
      is_busy = true;
      should_finish = std::max(should_finish, a[i].t) + a[i].d; 
      a[i].finish = should_finish;
      continue;
    }
    if (q.size() >= b && a[i].t < should_finish) {
      a[i].finish = -1;
      continue;
    }
    if (a[i].t >= should_finish) {
      if (q.size() > 0) {
        is_busy = true;
        should_finish = std::max(q.front()->t, should_finish) + q.front()->d;
        q.front()->finish = should_finish;
        q.pop();
      } else {
        is_busy = false;
      }
    }
    if (!is_busy) {
      is_busy = true;
      a[i].finish = std::max(should_finish, a[i].t) + a[i].d;
      should_finish = a[i].finish;
      continue;
    }
    if (q.size() < b) {
      q.push(&a[i]);
    }
  }
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    should_finish = max(should_finish, p->t) + p->d;
    p->finish = should_finish;
  }
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[a[i].id] = a[i].finish;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n" [i == n];
  }
  return;
}
signed main() {
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