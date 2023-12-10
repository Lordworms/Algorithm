#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1000;
const int N = 5e5 + 10;
int pre_pos[N], suf_pos[N], pos[N];
string s, t;
void solve() {
  cin >> s >> t;
  int slen = s.size();
  int tlen = t.size();
  int j = 0;

  memset(pos, 0, sizeof(pos));
  for (int i = 0; i < slen; i++) {
    if (j < tlen && s[i] == t[j]) {
      pos[s[i]] = j;
      j++;
    }
    pre_pos[i] = pos[s[i]];
  }

  j = tlen - 1;
  memset(pos, 0, sizeof(pos));
  for (int i = slen - 1; i >= 0; i--) {
    if (j >= 0 && s[i] == t[j]) {
      pos[s[i]] = tlen - j;
      j--;
    }
    suf_pos[i] = pos[s[i]];
  }

  for (int i = 0; i < slen; i++) {
    if (pre_pos[i] + suf_pos[i] < tlen) {
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");

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
