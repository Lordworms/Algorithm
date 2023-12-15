#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct Rec {
  ll w, h;
  int id;
};
void solve() {
  int n;
  cin >> n;
  ll w, h;
  vector<Rec> W(n + 2), H(n + 2);
  ll Area = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> w >> h;
    W[i] = H[i] = Rec{w, h, i};
    Area += w * h;
  }
  sort(W.begin() + 1, W.end(), [&](Rec a, Rec b) { return a.w > b.w; });
  sort(H.begin() + 1, H.end(), [&](Rec a, Rec b) { return a.h > b.h; });
  // pointer of h array and w array along with the visit array
  int hp = 1, wp = 1;
  vector<int> vis(n + 1);
  function<bool(ll, ll, int, int)> dfs = [&](ll cur_w, ll cur_h, int hp,
                                             int wp) {
    if (cur_w * cur_h == 0) return true;
    // move pointer first
    while (wp <= n && vis[W[wp].id]) ++wp;
    while (hp <= n && vis[H[hp].id]) ++hp;

    if (cur_w == W[wp].w) {
      vis[W[wp].id] = 1;
      return dfs(cur_w, cur_h - W[wp].h, hp, wp);
    }
    if (cur_h == H[hp].h) {
      vis[H[hp].id] = 1;
      return dfs(cur_w - H[hp].w, cur_h, hp, wp);
    }
    return false;
  };
  ll answ1 = -1, answ2 = -1, ansh1 = -1, ansh2 = -1;
  bool check_w = false, check_h = false;
  if (Area % W[1].w == 0) {
    answ1 = W[1].w;
    ansh1 = Area / W[1].w;
    vis[W[1].id] = 1;
    if (dfs(answ1, ansh1 - W[1].h, 1, 1)) {
      check_w = true;
    }
  }
  fill(vis.begin(), vis.end(), 0);
  if (Area % H[1].h == 0) {
    ansh2 = H[1].h;
    answ2 = Area / H[1].h;
    vis[H[1].id] = 1;
    if (dfs(answ2 - H[1].w, ansh2, 1, 1)) {
      check_h = true;
    }
  }
  if (check_w && check_h) {
    if (answ2 == answ1) {
      cout << 1 << '\n';
      cout << answ1 << ' ' << ansh1 << '\n';
    } else {
      cout << 2 << '\n';
      cout << answ1 << ' ' << ansh1 << '\n';
      cout << answ2 << ' ' << ansh2 << '\n';
    }
  } else if (check_w) {
    cout << 1 << '\n';
    cout << answ1 << ' ' << ansh1 << '\n';
  } else if (check_h) {
    cout << 1 << '\n';
    cout << answ2 << ' ' << ansh2 << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}