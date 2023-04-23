#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
const int INV=500000004;
ll quick_pow(ll x,ll exp,int p)
{
      ll ans=1;
      while(exp)
      {
        if(exp&1)ans=ans*x%p;
        exp>>=1;
        x=x*x%p;
      }
      return ans;
}
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>E(n+1),fa(n+1,vector<int>(32));
  vector<int>dep(n+1);
  for(int i=1;i<=n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  function<void(int,int)>dfs=[&](int x,int f){
    fa[x][0]=f;
    dep[x]=dep[f]+1;
    for(int i=1;i<20;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int v:E[x]){
        if(v==f)continue;
        dfs(v,x);
    }
  };
  function<int(int,int)>LCA=[&](int x,int y){
    if(dep[x]<dep[y])swap(x,y);//x is deeper
    for(int i=19;i>=0;--i){
        if(dep[x]-(1<<i)>=dep[y]){
            x=fa[x][i];
        }
    }
    if(x==y)return x;
    for(int i=19;i>=0;--i){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i],y=fa[y][i];
        }
    }
    return fa[x][0];
  };
  vector dp(n+1,vector<int>(n+1));
  for(int i=1;i<=n;++i){
    dp[0][i]=1;
  }
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])*INV%MOD;
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i){
    dfs(i,0);
    for(int j=1;j<=n;++j){
        for(int k=1;k<j;++k){
            int lca=LCA(j,k);
            ans=(ans+dp[dep[j]-dep[lca]][dep[k]-dep[lca]])%MOD;
        }
    }
  }
  cout<<ans*quick_pow(n,MOD-2,MOD)%MOD<<'\n';
  return;
}
signed main(){
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