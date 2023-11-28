#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> p;
  map<int, int> beg, end;
  int l, r;
  for (int i = 1; i <= n; ++i) {
    cin >> l >> r;
    p.push_back(l);
    p.push_back(r);
    beg[l]++;
    end[r]++;
  }
  sort(p.begin(), p.end());
  vector<pair<int, int>> ans;
  int alive = 0, st = 0;
  bool sign = false;
  for (int &cur : p) {
    if (beg.count(cur) && !end.count(cur)) {
      ++alive;
    } else if (!beg.count(cur) && end.count(cur)) {
      --alive;
    } else if (beg.count(cur) && end.count(cur)) {
      if (beg[cur] != 0) {
        ++alive;
        beg[cur]--;
      } else {
        --alive;
      }
    }
    if (!sign && alive == k) {
      sign = true;
      st = cur;
    } else if (sign && alive < k) {
      sign = false;
      ans.push_back({st, cur});
    }
  }
  std::cout << ans.size() << '\n';
  for (auto &p : ans) {
    cout << p.first << ' ' << p.second << '\n';
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