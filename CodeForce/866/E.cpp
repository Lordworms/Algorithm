#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void solve() {
  int n, u, v;
  cin >> n;
  vector<vector<int>> E(n + 1);
  vector<int> deg(n + 1), beg(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) {
      beg.push_back(i);
      --deg[i];
    }
  }
  for (auto &v : beg) {
    for (int &to : E[v]) {
      --deg[to];
    }
  }
  int st = 1;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) {
      st = i;
    }
    if (deg[i] > 2) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
  vector<int> ans;
  ans.push_back(-1);
  bool not_stop = true;
  int fa = 0;
  for (int i = st; not_stop;) {
    ans.push_back(i);
    not_stop = false;
    for (auto &v : E[i]) {
      if (v != fa && E[v].size() != 1) {
        fa = i;
        i = v;
        not_stop = true;
        break;    
      }
    }
  }
  int len = ans.size() - 1;
  ans.push_back(-1);
  for (int i = 1; i <= len; ++i) {
    if (i & 1) {
      cout << ans[i] << ' ';
    } else {
      for (auto &v : E[ans[i]]) {
        if (v != ans[i - 1] && v != ans[i + 1]) {
          cout << v << ' ';    
        }        
      }
    }
  }
  for (int i = len; i >= 1; --i) {
    if (i & 1) {
      for (auto &v : E[ans[i]]) {
        if (v != ans[i - 1] && v != ans[i + 1]) {
          cout << v << ' ';
        }  
      }  
    } else {
      cout << ans[i] << ' ';
    }
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