#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 43;
ll fib[N + 1];
map<ll, int> id;
void init() {
  fib[0] = fib[1] = 1;
  id[1] = 0;
  id[2] = 1;
  ll sum = 2;
  for (int i = 2; i < N; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    sum += fib[i];
    id[sum] = i;
  }
}
void solve() {
  int k;
  cin >> k;
  ll sum = 0; 
  vector<ll> a(k + 1);
  for (int i = 1; i <= k; ++i) {
    cin >> a[i];  
    sum += a[i];
  }
  if (id.find(sum) == id.end()) {
    cout << "NO" << '\n';
    return; 
  }
  int st = id[sum], last = 0;
  for (int i = st; i >= 0; --i) {
    int cur = -1;
    for (int j = 1; j <= k; ++j) { 
      if (j != last) {
        if (cur == -1 || a[cur] < a[j]) {
          cur = j;
        }
      }  
    }
    if (cur == -1 || a[cur] < fib[i]) {
      cout << "NO" << '\n';
      return;
    }
    a[cur] -= fib[i];
    last = cur;
  }
  cout << "YES" << '\n';
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