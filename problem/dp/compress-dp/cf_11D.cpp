#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define lowbit(x) (x&-x)
void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<ll>>dp(1ll<<n,vector<ll>(n));
  vector<vector<int>>mp(n,vector<int>(n));
  for(int i=0;i<m;++i){
    int u,v;
    cin>>u>>v;
    --u,--v;
    mp[u][v]=mp[v][u]=1;
  }
  ll ans=0;
  for(int i=0;i<n;++i)dp[1<<i][i]=1;
  for(int sta=0;sta<(1<<n);++sta){
    for(int id=0;id<n;++id){
        if(!dp[sta][id]){
            continue;
        }
        for(int k=0;k<n;++k){
            if(!mp[id][k])continue;
            if(lowbit(sta)>(1<<k))continue;
            if(1<<k&sta){
                if(1<<k==lowbit(sta)){
                    ans+=dp[sta][id];
                }
            }else{
                dp[sta|(1<<k)][k]+=dp[sta][id];// if did not run on it then walk!
            }
        }
    }
  } 
  cout<<((ans-m)>>1)<<'\n';//minus the common road 
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