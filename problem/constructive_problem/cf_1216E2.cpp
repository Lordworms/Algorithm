#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int q;
  cin >> q;
  ll k;
  function<ll(ll, ll)> get = [&](ll x, ll op) {
    ll ssum = 0, sum = 0, cnt, exp = 1, len = 0;
    while (1) {
      exp *= 10;
      ++len;
      if (x > exp - 1) {
        cnt = exp - exp / 10; // how many number between [10^i, 10^(i + 1)]
        ssum += sum * cnt + cnt * (cnt + 1) * len / 2;
        sum += len * cnt; // total length of number between [10^i, 10^(i + 1)]
      } else {
        cnt = x - exp/10 + 1; // how many number between the interval;
        ssum += sum * cnt + cnt * (cnt + 1) * len / 2; // total length: contains cnt sum and the extra shit
        sum += len * cnt; // the total length between interval [10^cnt, 10^ (cnt + 1)] 
        break;
      }
    }  
    return op ? ssum : sum; 
  };
  while (q--) {
    cin >> k;
    int l = 0, r = 1e9, m, cur;
    while (l <= r) {
      m = (l + r) >> 1;
      if (get(m, 1) < k) {
        cur = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    k -= get(cur, 1);
    l = 0, r = cur + 1;
    while (l <= r) {
      m = (l + r) >> 1;
      if (get(m, 0) < k) {
        cur = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    k -= get(cur , 0);
    ++cur;
    cout << to_string(cur)[k - 1] << '\n';
  } 
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