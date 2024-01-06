#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int tr[N * 30][2], CNT[N * 30];
int cnt = 0;
void insert(int x) {
  int u = 0;
  for (int i = 30; i >= 0; --i) {
    int cur = 0;
    if (x & (1 << i)) {
      cur = 1;
    }
    if (!tr[u][cur]) {
      tr[u][cur] = ++cnt;
    }
    u = tr[u][cur];
    CNT[u]++;
  }
}
void remove(int x) {
  int u = 0;
  for (int i = 30; i >= 0; --i) {
    int cur = 0;
    if (x & (1 << i)) {
      cur = 1;
    }
    int t = u;
    u = tr[u][cur];
    CNT[u]--;
    if (CNT[u] == 0) {
      tr[t][cur] = 0;
      return;
    }
  }
}
int get(int x) {
  int u = 0, ans = 0;
  for (int i = 30; i >= 0; --i) {
    int cur_x = ((x & (1 << i)) == 0) ? 0 : 1;
    if (tr[u][!cur_x]) {
      ans += (1 << i);
      u = tr[u][!cur_x];
    } else {
      u = tr[u][cur_x];
    }
  }
  return ans;
}
void solve() {
  int q, x;
  cin >> q;
  insert(0);
  while (q--) {
    char type;
    cin >> type >> x;
    if (type == '+') {
      insert(x);
    } else if (type == '-') {
      remove(x);
    } else {
      cout << get(x) << '\n';
    }
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