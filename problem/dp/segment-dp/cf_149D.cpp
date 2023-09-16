#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 710;
string s;
// dp[l][r][c1][c2] represent the number of ways to color range [l,r] with s[l]
// = c1  and s[r] = c2;
ll dp[N][N][3][3];
int match[N];
void init() {
  stack<int> st;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      match[i] = st.top();
      match[st.top()] = i;
      st.pop();
    }
  }
}
void dfs(int l, int r) {
  // case 1: directly color the neighbors
  if (l + 1 == r) {
    dp[l][r][0][1] = 1;
    dp[l][r][1][0] = 1;
    dp[l][r][2][0] = 1;
    dp[l][r][0][2] = 1;
    return;
  }
  // case 2: it is one big range, we just need to merge them
  if (match[l] == r) {
    dfs(l + 1, r - 1);
    for (int c1 = 0; c1 < 3; ++c1) {
      for (int c2 = 0; c2 < 3; ++c2) {
        if (c2 != 1) {
          (dp[l][r][0][1] += dp[l + 1][r - 1][c1][c2]) %= MOD;
        }
        if (c2 != 2) {
          (dp[l][r][0][2] += dp[l + 1][r - 1][c1][c2]) %= MOD;
        }
        if (c1 != 1) {
          (dp[l][r][1][0] += dp[l + 1][r - 1][c1][c2]) %= MOD;
        }
        if (c1 != 2) {
          (dp[l][r][2][0] += dp[l + 1][r - 1][c1][c2]) %= MOD;
        }
      }
    }
    return;
  }
  // two big ranges we need to merge them seperately
  int k = match[l];
  dfs(l, k);
  dfs(k + 1, r);
  for (int c1 = 0; c1 < 3; ++c1) {
    for (int c2 = 0; c2 < 3; ++c2) {
      for (int c3 = 0; c3 < 3; ++c3) {
        for (int c4 = 0; c4 < 3; ++c4) {
          if (!(c2 == 1 && c3 == 1 || c2 == 2 && c3 == 2)) {
            (dp[l][r][c1][c4] += (dp[l][k][c1][c2] * dp[k + 1][r][c3][c4])) %= MOD;
          }
        }
      }
    }
  }
}
void solve() {
  cin >> s;
  init();
  dfs(0, s.size() - 1);
  ll ans = 0;
  for (int c1 = 0; c1 < 3; ++c1) {
    for (int c2 = 0; c2 < 3; ++c2) {
      (ans += dp[0][s.size() - 1][c1][c2]) %= MOD;
    } 
  }
  cout << ans << '\n';
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