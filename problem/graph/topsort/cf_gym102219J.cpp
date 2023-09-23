#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  string s;
  vector<vector<int>> E(5);
  vector<int> deg(5), level(5);
  for (int i = 0; i < 5; ++i) {
    cin >> s;
    char cmp = s[1];
    if (cmp == '<') {
      E[s[0] - 'A'].push_back(s[2] - 'A');
      deg[s[2] - 'A']++;
    } else {
      E[s[2] - 'A'].push_back(s[0] - 'A');
      deg[s[0] - 'A']++;
    }
  } 
  deque<int> q;
  for (int i = 0; i < 5; ++i) {
    if (!deg[i]) {
      q.push_back(i);
      level[i] = 1;
    }
  }
  int total = 0;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop_front();  
    for (int x : E[cur]) {
      --deg[x];
      if (!deg[x]) {
        q.push_back(x);
        level[x] = level[cur] + 1;
      }
    }
  }
  for (int i = 0; i < 5; ++i) {
    if (deg[i]) {
      cout << "impossible" << '\n';
      return;
    }
  }
  vector<char> ans = {'A', 'B', 'C', 'D', 'E'};
  sort(ans.begin(), ans.end(), [&] (char a, char b) {
    return level[a - 'A'] < level[b - 'A'];
  });
  for (int i = 0; i < 5; ++i) {
    cout << ans[i];
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