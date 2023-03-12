#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  string s;cin>>s;
  vector<int>dp(n+1,0);
  for(int i=1;i<=n;++i){
    if(s[i-1]=='1'){
        dp[i]=dp[i-1]+1;
    }else{
        dp[i]=dp[i-1]-1;
    }
  }
  map<int,int>mp;
  mp[0]=0;
  int ans=0;
  for(int i=1;i<=n;++i){
    if(mp.count(dp[i])){
        ans=max(ans,i-mp[dp[i]]);
    }else{
        mp[dp[i]]=i;
    }
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