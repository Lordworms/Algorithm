#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXM=1e5+20;
const int MAXN=400;
int dp[MAXN][MAXM];
int a[MAXN];
void solve(){
  int n;
  cin>>n;
  int m=sqrt(n);
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=n;i>=1;--i){
    for(int j=1;j<=m;++j){
        if(i+a[i]+j>n){
            dp[i][j]=1;
        }else{
            dp[i][j]=dp[i+a[i]+j][j]+1;
        }
    }
  }
  int q;
  cin>>q;
  
  while(q--){
    int p,k;
    cin>>p>>k;
    if(k<=m){
        cout<<dp[p][k]<<'\n';
    }else{
        int ans=0;
        while(p<=n){
            ++ans;
            p+=a[p]+k;
        }
        cout<<ans<<'\n';
    }
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