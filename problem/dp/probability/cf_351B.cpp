#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  int cnt=0;
  for(int i=1;i<n;++i){
    for(int j=0;j<i;++j){
        if(a[j]>a[i]){
            ++cnt;
        }
    }
  }
  double ans=0;
  if(cnt&1){
    ans=2*cnt-1;
  }else{
    ans=2*cnt;
  }
  //dp[i]=0.5dp[i-2]+0.5*dp[i]+2;
  printf("%.6f",ans);
  return;
}
int main(){
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