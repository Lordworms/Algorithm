#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s;
  cin>>s;
  int n=s.size();
  s='*'+s+'*'+'#';
  vector dp(n+2,vector<int>(n+2));
  vector pad(n+2,vector<int>(n+2,-1));
  function<int(int,int)>dfs=[&](int l,int r){
      if(pad[l][r]!=-1)return pad[l][r];
      if(s[l]!=s[r])return 0;
      pad[l+1][r-1]=dfs(l+1,r-1);
      return pad[l+1][r-1];
  };
  for(int i=1;i<=n;++i){
    dp[i][i+1]=(s[i]==s[i+1])+2;
    dp[i][i]=1;
    pad[i][i]=dp[i][i];
    pad[i][i+1]=(dp[i][i+1]==3);
  }
  //dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+s[i..j]==pad
  for(int len=3;len<=n;++len){
    for(int l=1;l+len-1<=n;++l){
      int r=l+len-1;
      pad[l][r]=dfs(l,r);
      dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+pad[l][r];
    }
  }
  int q;
  cin>>q;
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<dp[l][r]<<'\n';
  }
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