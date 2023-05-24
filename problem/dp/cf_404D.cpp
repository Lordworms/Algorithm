#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s;
  cin>>s;
  int n=s.size();
  s=')'+s;
  vector dp(n+1,vector<int>(5));//0:itself is a minner, 1:only left has a minner 2:only right has a minner 3:left and right both have miners 4:non of them has a miner
  dp[0][4]=dp[0][2]=1;
  bool able=false;
  for(int i=1;i<=n;++i){
    able=s[i]=='?';
    if(able||s[i]=='*'){
        dp[i][0]=(dp[i][0]+dp[i-1][0])%MOD;
        dp[i][0]=(dp[i][0]+dp[i-1][2])%MOD;
        dp[i][0]=(dp[i][0]+dp[i-1][3])%MOD;
    }
    if(able||s[i]=='0'){
        dp[i][4]=(dp[i][4]+dp[i-1][1])%MOD;
        dp[i][4]=(dp[i][4]+dp[i-1][4])%MOD;
    }
    if(able||s[i]=='1'){
        dp[i][1]=(dp[i][1]+dp[i-1][0])%MOD;
        dp[i][2]=(dp[i][2]+dp[i-1][4])%MOD;
        dp[i][2]=(dp[i][2]+dp[i-1][1])%MOD;
    }
    if(able||s[i]=='2'){
        dp[i][3]=(dp[i][3]+dp[i-1][0])%MOD;
    }
  }
  ll ans=0;
  able=s[n]=='?';
  if(able||s[n]=='*')ans=(ans+dp[n][0])%MOD;
  if(able||s[n]=='0')ans=(ans+dp[n][4])%MOD;
  if(able||s[n]=='1')ans=(ans+dp[n][1])%MOD;
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