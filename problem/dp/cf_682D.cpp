#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  map<char,int>mp;
  int n,m,k;
  cin>>n>>m>>k;
  string s,t;
  cin>>s>>t;
  s=')'+s;
  t=')'+t;
  int dp[n+1][m+1][k+1];
  memset(dp,0,sizeof(dp));
  for(int kk=1;kk<=k;++kk){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i]==t[j]){
                dp[i][j][kk]=max(dp[i-1][j-1][kk-1],dp[i-1][j-1][kk])+1;
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dp[i][j][kk]=std::max({dp[i][j][kk],dp[i-1][j][kk],dp[i][j-1][kk]});
        }
    }
  }
  cout<<dp[n][m][k]<<'\n';
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