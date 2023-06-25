#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
void solve(){
  string s;
  cin>>s;
  int n=s.size();
  s=')'+s;
  vector dp(n+1,vector<ll>(3,INF)),trace(dp);
  if(n==1){
    if((s[1]-'0')%3==0)cout<<s[1]<<'\n';
    else cout<<-1<<'\n';
    return;
  }
  dp[1][0]=1;
  dp[1][(s[1]-'0')%3]=0;
  for(int i=2;i<=n;++i){
    int num=s[i]-'0';
    int rem=num%3;
    for(int j=0;j<3;++j){
        dp[i][j]=dp[i-1][j]+1;
        trace[i][j]=j;
        if(s[i]=='0'&&dp[i-1][j]==i-1)continue;
        if(dp[i-1][(j-rem+3)%3]<dp[i][j]){
            dp[i][j]=dp[i-1][(j-rem+3)%3];
            trace[i][j]=(j-rem+3)%3;
        }
    }   
  }
  if(dp[n][0]==n){
    for(int i=1;i<=n;++i){
        if(s[i]=='0'){
            cout<<s[i]<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
    return;
  }
  int pre;
  vector<char>ans;
  for(int i=n,j=0;i>=2;j=pre,--i){
    pre=trace[i][j];
    if(dp[i-1][pre]==dp[i][j]){
        ans.push_back(s[i]);
    }
  }
  if((s[1]-'0')%3==pre){
    ans.push_back(s[1]);
  }
  for(int i=ans.size()-1;i>=0;--i){
    cout<<ans[i];
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