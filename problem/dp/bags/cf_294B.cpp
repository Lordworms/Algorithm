#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>w(n+1),t(n+1);
  int sum=0,sumw=0;
  for(int i=1;i<=n;++i){
    cin>>t[i]>>w[i];
    sum+=t[i];//total thickness
    sumw+=w[i];
  }
  vector<int>dp(sum+1,-1e9);
  dp[0]=0;
  for(int i=1;i<=n;++i){
    for(int v=sum;v>=t[i];--v){
        dp[v]=max(dp[v],dp[v-t[i]]+w[i]);//花费i厚度能获得dp[i]的宽度
    }
  }
  for(int i=1;i<=sum;++i){
    if(dp[i]+i>=sumw){//能够掩盖住
        cout<<i<<'\n';
        break;
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