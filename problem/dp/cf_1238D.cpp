/**
 * totally four different kinds of bad string:
 * AAAAAA...B
 * BBBBBB...A
 * ABBB.....B
 * BAAA.....A
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 3e5 + 10;
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(N, 1);
  int pos = 0, c = 0;
  for (int i = 1; i < n; ++i) {
    if(s[i] == s[pos]) {
      cnt[c]++;
    } else {
      ++c;
      cnt[c] = 1;
      pos = i;
    }
  } 
  ll ans = n * (n - 1) >> 1;
  for (int i = 1; i <= c; ++i) { 
    ans -= cnt[i - 1] + cnt[i] - 1; 
  }
  cout << ans << '\n';
  return ;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in","r",stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out","w",stdout);
#endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}