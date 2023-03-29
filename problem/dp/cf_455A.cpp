/*
    cnt[x] means the times that x happen in the list

    dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
#define int ll
void solve(){
  int n;
  cin>>n;
  vector<int>cnt(MAXN);
  vector<int>dp(cnt);
  for(int i=0;i<n;++i){
    int x;cin>>x;
    cnt[x]++;
  }
  dp[1]=cnt[1];
  dp[0]=0;
  for(int i=2;i<MAXN;++i){
    dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
  }
  cout<<dp[MAXN-1]<<'\n';
  return;
}
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}