/*
    the centroid lies in the path from its root and its heavy son
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,q;cin>>n>>q;
  vector<int>fa(n+1),ans(n+1),hson(n+1),siz(n+1);
  vector<vector<int>>E(n+1);
  for(int i=2;i<=n;++i){
    int x;cin>>x;
    E[x].push_back(i);
    fa[i]=x;
  }
  function<void(int)>dfs1=[&](int now){
    siz[now]=1;
    for(int v:E[now]){
        dfs1(v);
        siz[now]+=siz[v];
        if(siz[v]>siz[hson[now]]){
            hson[now]=v;
        }
    }
  };
  function<void(int)>dfs2=[&](int now){
    if(!hson[now]){
        ans[now]=now;
        return;
    }
    for(int v:E[now]){
        dfs2(v);
    }
    if(2*siz[hson[now]]<=siz[now]){
        ans[now]=now;
    }
    else{
        for(int v=ans[hson[now]];v!=now;v=fa[v]){
            if(max(siz[hson[v]],siz[now]-siz[v])*2<=siz[now]){
                ans[now]=v;
                break;
            }
        }
    }
  };
  dfs1(1);
  dfs2(1);
  while(q--){
    int v;cin>>v;
    cout<<ans[v]<<'\n';
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