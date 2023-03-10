#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
const int N=1e5+10;
ll dp[N][201][3];////0 eq, 1 less 2 greater
void solve(){
  int n;cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  if(a[1]==-1){
    for(int i=1;i<=200;++i){
        dp[1][i][2]=1;
    }
  }else{
    dp[1][a[1]][2]=1;
  }
  
  for(int i=2;i<=n;++i){ 
    int sum=0;
    for(int j=1;j<=200;++j){
        if(a[i]==-1||a[i]==j){
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
            dp[i][j][2]=sum%MOD;
        }
        sum=(sum+dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
    }
    sum=0;
    //calculate less than previous
    for(int j=200;j>=1;--j){
        if(a[i]==-1||a[i]==j){
            dp[i][j][1]=sum%MOD;
        }
        sum=(sum+(dp[i-1][j][0]+dp[i-1][j][1]))%MOD;
    }
  }
  ll ans=0;
  for(int i=1;i<=200;++i){
    ans=(ans+(dp[n][i][0]+dp[n][i][1]))%MOD;
  }
  cout<<ans<<'\n';
  return;
}
int main(){
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