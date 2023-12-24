#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 1e5 + 100;
int prime[N], p[N];
int p_cnt;
using pii = pair<int, int>;
vector<pii> V[N];
int gcd(int a, int b) {
  return b? gcd(b, a % b): a;
}
void init() {
  p[0] = p[1] = -1;
  for (int i = 2; i < N; ++i) {
    if (!p[i]) {
      prime[++p_cnt] = i;  
      p[i] = i;
    }
    for (int j = 1; j <= p_cnt && i * prime[j] < N; ++j) {
      p[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) { // which means we have iterate before
        break;
      }
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> dec(n + 1);
  // initialization
  dec[0] = k;
  for (int i = 0; i <= n; ++i) {
    if (i) cin >> dec[i];
    dec[i] = gcd(dec[i], k);
    int tmp = dec[i];
    for (int j = 1; j <= p_cnt && prime[j] <= tmp; ++j) {
      int cnt = 0;
      while (tmp % prime[j] == 0) {
        tmp /= prime[j];
        ++cnt;
      }
      if (cnt) V[i].push_back({prime[j], cnt}); // check if cnt > 0  or not
    }
    if (tmp) {
      V[i].push_back({tmp, 1});
    }
  }
  map<int, int> cur_cnt;
  auto check = [&] () {
    for (auto &p : V[0]) {
      if (cur_cnt[p.first] < p.second) {
        return false;
      }
    }  
    return true;
  };
  ll ans = 0;
  // using two pointer
  for (int l = 1, r = 1; r <= n; ++r) {
    for (auto &p : V[r]) {
      cur_cnt[p.first] += p.second;
    }
    while (l <= r && check()) {
      ans += n - r + 1;
      for (auto &p : V[l]) {
        cur_cnt[p.first] -= p.second;
      }
      ++l;
    }
  }
  cout << ans << '\n';
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
  init();
  while (T--) {
    solve();
  }
  return 0;
}