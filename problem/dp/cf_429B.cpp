#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  vector a(n+1,vector<int>(m+1));
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
        cin>>a[i][j];
    }
  }
  vector dp1(n+2,vector<int>(m+2)),dp2(dp1),dp3(dp1),dp4(dp1);
  for(int i=1;i<=n;++i){//左上角
    for(int j=1;j<=m;++j){
        dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
    }
  }
  for(int i=n;i>=1;--i){//右下角
    for(int j=m;j>=1;--j){
        dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+a[i][j];
    }
  }
  for(int i=1;i<=n;++i){//右上角
    for(int j=m;j>=1;--j){
        dp3[i][j]=max(dp3[i-1][j],dp3[i][j+1])+a[i][j];
    }
  }
  for(int i=n;i>=1;--i){//左下角
    for(int j=1;j<=m;++j){
        dp4[i][j]=max(dp4[i+1][j],dp4[i][j-1])+a[i][j];
    }
  }
  int ans=0;
  for(int i=2;i<n;++i){
    for(int j=2;j<m;++j){
        ans=max(ans,dp1[i-1][j]+dp2[i+1][j]+dp3[i][j+1]+dp4[i][j-1]);
        ans=max(ans,dp1[i][j-1]+dp2[i][j+1]+dp3[i-1][j]+dp4[i+1][j]);
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