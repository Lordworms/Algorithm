#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<vector<int>>E(n+1);
  for(int i=2;i<=n;++i){
    int p;
    cin>>p;
    E[p].push_back(i);
  }
  vector<int>dp(n+1),dep(n+1),low(n+1),ans(n+1);//dp[i]:the total leaf num it could get if use i to be the root and comes back to i in the end. low[i]:the smallest depth it could get in this senario. ans[i]: the total number could get using i to be the root and did not request to return to the root
  function<void(int,int)>dfs1=[&](int x,int f){
    dep[x]=dep[f]+1;
    if(E[x].size()==0){
        low[x]=dep[x];
        dp[x]=1;
    }else{
        int height=1e9;
        int value=0;
        for(int v:E[x]){
            if(v==f)continue;
            dfs1(v,x);
            if(low[v]-dep[x]<=k){
                value+=dp[v];
                height=min(height,low[v]);
            }
        }
        dp[x]=value;
        low[x]=height;
    }
  };
  dfs1(1,0);
  function<void(int,int)>dfs2=[&](int x,int f){
    ans[x]=dp[x];
    for(int v:E[x]){
        if(v==f)continue;
        dfs2(v,x);
        int tmp=dp[x];
        if(low[v]-dep[x]<=k)tmp-=dp[v];
        ans[x]=max(ans[x],tmp+ans[v]);
    }
  };
  dfs2(1,0);
  cout<<ans[1]<<'\n';
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