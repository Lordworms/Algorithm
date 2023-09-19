#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
int f[MAXN];
int find(int x) {
  return f[x] == x ? x : find(f[f[x]]);
}
void merge(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) return;
  f[fy] = fx;
}
ll quick_pow(ll x, ll exp) {
  ll base = x, ans = 1;
  while (exp) {
    if(exp & 1) ans = ans * base % MOD;
    base = base * base % MOD;
    exp >>= 1;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  iota(f + 1, f + n + 1, 1);
  vector<int> a(n + 1), b(n + 1), d(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    if (a[i] == b[i]) {
      f[find(a[i])] = 0;
      continue;
    }
    merge(a[i], b[i]);
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    if (d[i]) {
      f[find(d[i])] = 0;    
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (find(i) == i) {
      ++cnt;
    }
  }
  cout << quick_pow(2, cnt) << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}