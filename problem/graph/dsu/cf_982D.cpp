#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
struct Pos {
  int id, v;
  bool operator<(const Pos &a) const{ return v == a.v ? id < a.id : v < a.v; }
};
int f[N], siz[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  f[y] = x;
  siz[x] += siz[y];
}
// size to count
map<int, int> siz_cnt;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) siz[i] = 1;
  memset(f, -1, sizeof(f));
  f[0] = 0;
  vector<Pos> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].v;
    a[i].id = i;
  }
  sort(a.begin() + 1, a.end());
  int max_sz = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    f[a[i].id] = a[i].id;
    int &id = a[i].id;
    if (id + 1 <= n && f[id + 1] != -1) {
      int sz = siz[find(id + 1)];
      siz_cnt[sz]--;
      if (siz_cnt[sz] == 0) siz_cnt.erase(sz);
      merge(id + 1, id);
    }
    if (id - 1 >= 1 && f[id - 1] != -1) {
      int sz = siz[find(id - 1)];
      siz_cnt[sz]--;
      if (siz_cnt[sz] == 0) siz_cnt.erase(sz);
      merge(id - 1, id);
    }
    int cur_size = siz[find(id)];
    if (siz_cnt.count(cur_size) == 0) siz_cnt[cur_size] = 1;
    else siz_cnt[cur_size]++;
    if (siz_cnt.size() == 1) {
      if (siz_cnt[cur_size] > max_sz) {
        max_sz = siz_cnt[cur_size];
        ans = a[i].v + 1;
      }
    }
  }
  cout << ans << '\n';
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