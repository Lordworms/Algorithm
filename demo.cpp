/**
 *    author:  tourist
 *    created: 20.11.2022 19:01:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '1') {
          deg[i] += 1;//find the degree of i 
        }
      }
    }
    vector<bool> was(n, false);
    vector<vector<int>> all;
    for (int st = 0; st < n; st++) {
      if (was[st]) {
        continue;
      }
      vector<int> que(1, st);
      was[st] = true;
      for (int b = 0; b < (int) que.size(); b++) {
        for (int i = 0; i < n; i++) {
          if (!was[i] && s[que[b]][i] == '1') {
            was[i] = true;
            que.push_back(i);
          }
        }
      }
      all.push_back(que);
    }//all contains a point and its adjacent points
    if (all.size() == 1) {
      cout << 0 << '\n';
      continue;
    }
	//all contains all cliques
    int one = -1;
    for (auto& v : all) {
      int sz = (int) v.size();
      if (sz == 1) {//it is the feasible vertex
        one = v[0];
        break;
      }
      int cnt = 0;
      for (int x : v) {
        if (deg[x] == sz - 1) {//whether it is fully connected or intermediately connected
          cnt += 1;
        }
      }
      if (cnt == sz) {//fully connected
        continue;
      }
      if (cnt == 0) {
        one = v.back();
        break;
      }
      for (int x : v) {
        if (deg[x] < sz - 1) {
          one = x;
          break;
        }
      }
      break;
    }
    if (one != -1) {
      cout << 1 << '\n';
      cout << one + 1 << '\n';
      continue;
    }
    if (all.size() > 2) {
      cout << 2 << '\n';
      cout << all[0][0] + 1 << " " << all[1][0] + 1 << '\n';
      continue;
    }
    auto& v = (all[0].size() < all[1].size() ? all[0] : all[1]);
    cout << v.size() << '\n';
    for (int i = 0; i < (int) v.size(); i++) {
      cout << v[i] + 1 << " \n"[i == (int) v.size() - 1];
    }
  }
  return 0;
}
