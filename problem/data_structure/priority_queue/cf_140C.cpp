#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
struct Node {
  int a, b, c;
};
struct Tile {
  int v, cnt;  
  bool operator < (const Tile &t) const {
    return cnt < t.cnt;
  } 
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a.begin() + 1, a.end());
  vector<int> b;
  int val_cnt = 0;
  b.push_back(0);
  vector<int> beg_size;
  beg_size.push_back(0);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i - 1]) {
      b[b.size() - 1]++;
    } else {
      b.push_back(1);
      beg_size.push_back(a[i]);
    }
  }
  priority_queue<Tile> q;
  for (int i = 1; i < b.size(); ++i) {
    q.push({beg_size[i], b[i]});
  }
  val_cnt = b.size() - 1;
  vector<Node> ans;
  int ans_cnt = 0;
  if (q.size() < 3) {
    cout << "0" << '\n';
    return;
  }
  while (q.size() >= 3) {
    auto x = q.top(); q.pop();
    auto y = q.top(); q.pop();
    auto z = q.top(); q.pop();
    auto xr = x.v, yr = y.v, zr = z.v;
    if (xr < zr) swap(xr, zr);
    if (xr < yr) swap(xr, yr);
    if (yr < zr) swap(yr, zr);
    ans.push_back({xr, yr, zr});
    --x.cnt, --y.cnt, --z.cnt;
    if (x.cnt) {
      q.push(x);
    } 
    if (y.cnt) {
      q.push(y);
    }
    if (z.cnt) {
      q.push(z);
    } 
  }
  cout << ans.size() << '\n';
  for (auto &p : ans) {
    cout << p.a << ' ' << p.b << ' ' << p.c << '\n';
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