#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
set<int> st;
map<int, int> interv;
void solve() {
  int n, q, type, l, r, x;
  cin >> n >> q;
  // element in st means we could not determine whether this guy has fever or
  // not
  for (int i = 0; i <= n + 1; ++i) {
    st.insert(i);
  }

  while (q--) {
    cin >> type;
    switch (type) {
      case 0: {
        cin >> l >> r >> x;
        if (x == 0) {
          while (1) {
            auto it = st.lower_bound(l);
            if (*it > r) break;
            st.erase(*it);
          }
        } else {
          auto it = interv.lower_bound(l);
          if (it != interv.end() && it->second <= r) continue;
          interv[l] = r;
          it = interv.find(l);
          while (it != interv.begin() && r <= prev(it)->second)
            interv.erase(prev(it));
        }
        break;
      }
      case 1: {
        cin >> x;
        if (!st.count(x)) {
          cout << "NO" << '\n';
          continue;
        }
        int l = *prev(st.find(x)), r = *next(st.find(x));
        auto it = interv.upper_bound(l);
        if (it != interv.end() && it->first <= x && it->second < r) {
          cout << "YES" << '\n';
        } else {
          cout << "N/A" << '\n';
        }
        break;
      }
      default:
        break;
    }
  }
  return;
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