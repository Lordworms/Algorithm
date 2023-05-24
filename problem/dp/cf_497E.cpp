#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
void solve(){
  int n,a,b,k;
  cin>>n>>a>>b>>k;
  vector<int>dp(n+1),sum(n+1);
  if(a>b){// you could only move in one side of b(up or down)
    n-=b;
    a-=b;
  }else{
    n=b-1;
    a=b-a;
  }
  dp[a]=1;
  for(int i=a;i<=n;++i)sum[i]=1;
  for(int i=1;i<=k;++i){
    for(int j=1;j<=n;++j){
        dp[j]=((sum[n]-sum[j>>1])-dp[j]+MOD+MOD)%MOD;
    }
    for(int j=1;j<=n;++j){
        sum[j]=(sum[j-1]+dp[j])%MOD;
    }
  }
  cout<<sum[n]<<'\n';
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