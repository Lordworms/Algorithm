#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
int cnt;
const int N = 1e4 + 10;
int tr[N << 7][26], id[N << 7];
int get_index(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a';
  } else {
    return c - 'A';
  }
}
void insert(string s, int k) {
  int u = 0;
  for (int i = 0; i < s.size(); ++i) {
    int index = get_index(s[i]);
    if (!tr[u][index]) {
      tr[u][index] = ++cnt;
    }
    u = tr[u][index];
  }  
  id[u] = k;
}
void solve() {
  int n, k;
  string s;
  cin >> n >> s;
  cin >> k;
  vector<string> word(k + 1);
  for (int i = 1; i <= k; ++i) {
    cin >> word[i];
    insert(word[i], i);
  } 
  vector<int> dp(n + 1);
  for (int i = 0; i < n; ++i) {
    int u = 0;
    for (int j = i; j >= 0; --j) {
      int index = get_index(s[j]);
      if (!tr[u][index]) break;
      u = tr[u][index];
      if (id[u] && (j == 0 || dp[j - 1])) {
        dp[i] = id[u];
        break;
      }
    }
  }
  int len = n - 1;
  vector<string> ans;
  while (len >= 0) {
    ans.push_back(word[dp[len]]);
    len -= word[dp[len]].size();
  }
  for (int i = ans.size() - 1; i >= 0; --i) {
    cout << ans[i] << " \n" [i == n - 1];
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