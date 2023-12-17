#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 10;
int prime[MAXN], p[MAXN];
int p_cnt = 0;
void init() {
  p[0] = p[1] = -1;
  for (int i = 2; i < MAXN; ++i) {
    if (!p[i]) {
      prime[++p_cnt] = i;
      p[i] = i;
    }
    for (int j = 1; j <= p_cnt && i * prime[j] < MAXN; ++j) {
      p[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> b(n + 1);
  map<int, int> prime_cnt;
  int total_cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int x, cur = 0;
    cin >> x;
    for (int j = 1; j <= p_cnt && x >= prime[j]; ++j) {
      cur = 0;
      while (x % prime[j] == 0 && x) {
        ++cur;
        x /= prime[j];
      }
      if (x <= 0) break;
      if (cur) prime_cnt[prime[j]] += cur;
      total_cnt += cur;
    }
  }
  int odd_cnt = 0;
  for (auto &k : prime_cnt) {
    int &cur_cnt = k.second;
    if (cur_cnt % 2 == 1) {
      ++odd_cnt;
    }
  }
  if (odd_cnt && total_cnt <= 2) {
    cout << 0 << '\n';
    return;
  }
  if (total_cnt == 3) {
    cout << 1 << '\n';
    return;
  }
  int ans = 0;

  for (auto &k : prime_cnt) {
    ans += k.second / 2;
  }
  ans += odd_cnt / 3;
  cout << ans << '\n';
  /*
    1
    1
    0
    2
    2
    3
    4
    15
  */
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt", "r", stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt", "w", stdout);
#endif
  init();
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}