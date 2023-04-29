#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>E(n+1);
  vector<int>c(n+1);
  for(int i=0;i<n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for(int i=1;i<=n;++i)cin>>c[i];
  vector<int>dp(n+1);
  function<void(int,int)>dfs1=[&](int x,int f){
    dp[x]=1;
    for(int v:E[x]){
        if(v==f)continue;
        dfs1(v,x);
        if(c[x]!=c[v]||dp[v]!=1){
            dp[x]=0;
        }
    }
  };
  dfs1(1,0);
  function<int(int,int,int)>dfs2=[&](int x,int f,int last){
    int cnt1=0,cnt2=0,nxt=-1;
    for(int v:E[x]){
        if(v==f)continue;
        if(dp[v]){
            ++cnt1;
            if(c[v]==c[x]){
                ++cnt2;//how many subtrees are the same color as root
            }
        }else{
            nxt=v;
        }
    }
    int siz=E[x].size();
    if(x!=1)--siz;
    if(cnt1==siz){
        return x;
    }
    if(cnt2==siz-1&&c[x]==last){
        int res=dfs2(nxt,x,c[x]);
        if(res!=-1){
            return res;
        }
    }
    return -1;
  };
  int ans=dfs2(1,0,c[1]);
  if(ans!=-1){
    cout<<"YES"<<'\n'<<ans;
  }else{
    cout<<"NO\n";
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