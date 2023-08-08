#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
int nxt[N];
void solve() {
  int n;
  cin >> n;
  string ans;
  cin >> ans;
  string sc;
  function<void(string)> get_next = [&](string s) {
    int len = s.size();
    s = ')' + s;
    int j = 0;
    nxt[0] = nxt[1] = 0;
    for (int i = 2; i <= len; ++i) {
      while (j && s[j + 1] != s[i]) {
        j = nxt[j];
      }
      if (s[i] == s[j + 1]) {
        ++j;
      }
      nxt[i] = j;
    }
  };
  for (int i = 2; i <= n; ++i) {
    cin >> sc;
    int len = min(sc.size(), ans.size());
    string cur = sc + "!@#$%^&*()WETUIOPPLKJHGFDDSSSDVBNMM<KJJHGFD" +
                 ans.substr(ans.size() - len, len);
    get_next(cur);
    for (int j = nxt[cur.size()]; j < sc.size(); ++j) {
      ans += sc[j];
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