#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
void solve(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  s=')'+s;
  map<char,int>mp;
  vector<int>a(n+1);
  vector dp(n+1,vector<int>(5));
  mp['h']=1,mp['a']=2,mp['r']=3,mp['d']=4;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    for(int j=1;j<=4;++j){
        if(mp[s[i]]==j){
            if(j!=1){
                dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+a[i]);
            }else{
                dp[i][j]=dp[i-1][j]+a[i];
            }
        }else{
            dp[i][j]=dp[i-1][j];
        }
    }
  }
  cout<<dp[n][4]<<"\n";
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