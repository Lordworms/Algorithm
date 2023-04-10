#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
constexpr int N=(1<<10)+1;
void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  int lim=1<<n;
  vector<vector<int>>E(n);
  for(int i=0;i<m;++i){
    int u,v;
    cin>>u>>v;
    --u,--v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector dp(lim,vector<int>(lim));
  vector<int>cnt(lim+1);
  for(int i=0;i<lim;++i){
    cnt[i]=__builtin_popcount(i);
  }
  for(int i=1;i<lim;i<<=1){
    dp[i][i]=1;
  }
  for(int total=0;total<lim;++total){
    for(int leaf=total;leaf;--leaf&=total){
        if(dp[total][leaf]){
            for(int now_node=0;now_node<n;++now_node){
                if(total&(1<<now_node)){
                    for(int new_node:E[now_node]){
                        if(!(total&(1<<new_node))){
                            int status;
                            if(cnt[total]==1){
                                status=total|(1<<new_node);
                            }else{
                                status=leaf&~(1<<now_node)|(1<<new_node);
                            }
                            if(!(status>>new_node+1)){//why？
                                dp[total|(1<<new_node)][status]+=dp[total][leaf];
                            }
                        }
                    }
                }
            }
        }
    }
  }
  ll ans=0;
  for(int i=0;i<lim;++i){
    if(cnt[i]==k){
        ans+=dp[lim-1][i];
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