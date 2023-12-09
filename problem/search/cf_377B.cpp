#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct Stu {
  int id, cap, cost;
};
struct Pro {
  int id, dif;
};
struct Result {
  int id, cost;
  bool operator<(const Result &a) const { return cost > a.cost; }
};
void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<Stu> a(n + 1);
  vector<Pro> b(m + 1);
  vector<int> tmp(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].dif;
    b[i].id = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].cap;
    a[i].id = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].cost;
  }
  sort(a.begin() + 1, a.end(), [&](Stu a, Stu b) { return a.cap < b.cap; });
  sort(b.begin() + 1, b.end(), [&](Pro a, Pro b) { return a.dif < b.dif; });
  vector<int> ans(m + 1);
  // check if we could finish within cur;
  function<bool(int)> check = [&](int days) {
    priority_queue<Result> q;
    int len = m, pos = n, tot = s;
    while (len >= 1) {
      // store the extra results to the queue
      while (pos >= 1 && a[pos].cap >= b[len].dif) {
        Result r;
        r.cost = a[pos].cost;
        r.id = a[pos].id;
        q.push(r);
        --pos;
      }
      if (q.size() == 0) return false;
      auto t = q.top();
      q.pop();
      tot -= t.cost;
      if (tot < 0) return false;
      for (int i = max(len - days, 1); i <= len; ++i) {
        tmp[b[i].id] = t.id;
      }
      len -= days;
    }
    for (int i = 1; i <= m; ++i) {
      ans[i] = tmp[i];
    }
    return true;
  };
  int l = 1, r = m, mind = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      mind = mid;
    } else {
      l = mid + 1;
    }
  }
  if (mind == -1) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << " \n"[i == m];
  }
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