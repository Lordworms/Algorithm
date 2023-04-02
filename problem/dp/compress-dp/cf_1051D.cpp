#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
const int N=1e3+10;
ll dp[N][2*N][2];//0 means equal 1 means not equal
void solve(){
  int n,k;
  cin>>n>>k;
  int cur,nxt;
  dp[1][1][0]=dp[1][2][1]=2;
  for(int i=2;i<=n;++i){
    for(int j=1;j<=k;++j){
        if(j==1){
            dp[i][j][0]=2;
        }else{
            dp[i][j][0]=(dp[i-1][j-1][0]+2*dp[i-1][j][1]+dp[i-1][j][0])%MOD;
            dp[i][j][1]=(dp[i-1][j][1]+dp[i-1][j-2][1]+2*dp[i-1][j-1][0])%MOD;
        }
    }
  }
  cout<<(dp[n][k][0]+dp[n][k][1])%MOD<<'\n';
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