#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
struct Prob {
  int a, t, id;
  bool operator < (const Prob &tmp) const {
    if (tmp.a == a) {
      return t < tmp.t; 
    }
    return a > tmp.a;
  }
};
void solve() {
  int n, t;
  cin >> n >> t;
  vector<Prob> a(n + 1);
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].a >> a[i].t;
    a[i].id = i;
  }
  /*
    rule I :  if current left time is not sufficient break it
    rule II : always find those problem which has a higher constraint
  */
  sort(a.begin() + 1, a.end(), [&](Prob a, Prob b) {
    return a.t < b.t;  
  });
  priority_queue<Prob> q;
  for (int i = 1; i <= n; ++i) {
    if (t < a[i].t) break;
    if (a[i].a > q.size()) {
      q.push(a[i]);
      t -= a[i].t;
    }
    while (!q.empty() && q.top().a < q.size()) {
      t += q.top().t;
      q.pop();
    }
  }
  cout << q.size() << '\n' << q.size() << '\n';
  while (q.size()) {
    cout << q.top().id << ' ';
    q.pop();
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