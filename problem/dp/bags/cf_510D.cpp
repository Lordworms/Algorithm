#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void solve(){
  int n;cin>>n;
  vector<int>l(n),c(n);
  for(int i=0;i<n;++i)cin>>l[i];
  for(int i=0;i<n;++i)cin>>c[i];
  map<int,int>dp;
  dp[0]=0;
  for(int i=0;i<n;++i){
    for(auto& k:dp){
        int tmp=gcd(l[i],k.first);
        if(dp[tmp]!=0){
            dp[tmp]=min(dp[tmp],k.second+c[i]);
        }else{
            dp[tmp]=k.second+c[i];
        }
    }
  }
  cout<<(dp.count(1)?dp[1]:-1)<<'\n';
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