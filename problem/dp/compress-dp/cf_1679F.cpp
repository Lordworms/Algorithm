#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=24;
#define lowbit(x) (x&-x)
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  vector<ll>sum(1<<n);
  for(int i=0;i<n;++i){
    cin>>a[i];
    sum[1<<i]=a[i];
  }
  int k;cin>>k;
  vector<int>no(2);
  for(int i=0;i<k;++i)cin>>no[i];
  vector<ll>dp(1<<n);
  for(int i=0;i<n;++i){
    dp[1<<i]=(a[i]!=no[0]&&a[i]!=no[1]?1:0);
  }
  for(int i=1;i<(1<<n);++i){
    sum[i]=sum[i^lowbit(i)]+sum[lowbit(i)];
    if(sum[i]==no[0]||sum[i]==no[1])continue;
    for(int j=i;j;j-=lowbit(j)){
        dp[i]+=dp[i^lowbit(j)];
        dp[i]%=MOD;
    }
  }
  cout<<dp[(1<<n)-1]<<'\n';
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