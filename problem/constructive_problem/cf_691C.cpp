#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  // we need to get the position of . and
  string s;
  cin >> s;
  auto print = [&](int x) {
    if (x) {
      cout << "E" << x;
    }
    return;
  };
  int a = -1, b = -1, c = s.size();
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') {
      c = i;
    }
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.' || s[i] == '0') {
      continue;
    }
    a = i;
    break;
  }
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == '.' || s[i] == '0') {
      continue;
    }
    b = i;
    break;
  }
  // just one
  if (a == b) {
    cout << s[a];
    if (c < a) print(c - a);
    else print(c - a - 1);
  } else {
    cout << s[a] << ".";
    for (int i = a + 1; i <= b; ++i) {
      if (s[i] == '.') continue;
      cout << s[i];
    }
    if (c < a) print(c - a);
    else print(c - a - 1);
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