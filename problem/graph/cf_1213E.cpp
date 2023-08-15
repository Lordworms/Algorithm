#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> mp(3, vector<int>(3, 1));
  mp[s[0] - 'a'][s[1] - 'a'] = 0;
  mp[t[0] - 'a'][t[1] - 'a'] = 0;
  char c1, c2, c3;
  cout << "YES" << '\n';
  // we could go back through a single char
  if (mp[0][0] && mp[1][1] && mp[2][2]) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (i == j || j == k || i == k) continue;
          if (mp[i][j] && mp[j][k]) {
            c1 = i + 'a';
            c2 = j + 'a';
            c3 = k + 'a';
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout << c1;
    }
    for (int i = 1; i <= n; ++i) {
      cout << c2;
    }
    for (int i = 1; i <= n; ++i) {
      cout << c3;
    }    
  } else { // we could not go back through a single char 
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (i == j || j == k || k == i) continue;
          if (mp[i][j] && mp[j][k] && mp[k][i]) {
            c1 = i + 'a';
            c2 = j + 'a';
            c3 = k + 'a';
          } 
        }
      }
    } 
    for (int i = 1; i <= n; ++i) {
      cout << c1 << c2 << c3;
    }
  }
  
  return ;
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