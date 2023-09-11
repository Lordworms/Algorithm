#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n + 1);
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  } 
  deque<int> q;
  vector<ll> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    // we maintain a queue to store the increasing queue
    while(q.size() && a[q.back()] >= a[i]) q.pop_back();
    q.push_back(i);
    while(q.size() && i - q.front() >= c) q.pop_front();
    if(i >= c) dp[i] = max(dp[i - 1], dp[i - c] + a[q.front()]);
  }
  cout << sum - dp[n] << '\n';
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