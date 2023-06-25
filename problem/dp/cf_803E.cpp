#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=3030;
int dp[MAXN][MAXN];
int base=1500;
void solve(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  memset(dp,-1,sizeof(dp));
  dp[0][1500]=0;
  for(int i=0;i<n;++i){
    for(int j=1500-k+1;j<=1500+k-1;++j){
        if(dp[i][j]==-1)continue;
        if(s[i]=='W'||s[i]=='?'){
            dp[i+1][j+1]=j;
        }
        if(s[i]=='L'||s[i]=='?'){
            dp[i+1][j-1]=j;
        }
        if(s[i]=='D'||s[i]=='?'){
            dp[i+1][j]=j;
        }
    }
  }
  if(dp[n][1500-k]==-1&&dp[n][1500+k]==-1){
    cout<<"NO\n";
    return;
  }
  int cur=1500+k;
  if(dp[n][1500+k]==-1){
    cur=1500-k;
  }
  for(int i=n-1;i>=0;--i){
    int pre=cur,cur=dp[i+1][cur];
    if(pre-cur==1){
        s[i]='W';
    }
    if(pre-cur==-1){
        s[i]='L';
    }
    if(pre-cur==0){
        s[i]='D';
    }
  }
  cout<<s<<'\n';
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