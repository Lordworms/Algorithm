#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e3+10;
ll dp[N][2];
void solve(){
  int n,k,d;
  cin>>n>>k>>d;
  dp[0][0]=1;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=k;++j){
        if(i-j<0)break;
        if(j>=d){
            dp[i][1]=(dp[i][1]+(dp[i-j][0]+dp[i-j][1])%MOD)%MOD;
        }else{
            dp[i][0]=(dp[i][0]+(dp[i-j][0]))%MOD;
            dp[i][1]=(dp[i][1]+dp[i-j][1])%MOD;
        }
    }
  }
  cout<<dp[n][1]<<'\n';
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