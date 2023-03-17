#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
vector<int>fa;
vector<ll>sum;
int find(int x){
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx==fy)return;
  sum[fx]+=sum[fy];
  fa[fy]=fx;
}
void solve(){
  int n;cin>>n;
  fa.resize(n+1);
  sum.resize(n+1);
  iota(fa.begin(),fa.end(),0);
  vector<int>ord(n+1),vis(n+2);
  for(int i=1;i<=n;++i)cin>>sum[i];
  for(int i=1;i<=n;++i)cin>>ord[i];
  vector<ll>ans(n+1);
  ll res=0;
  for(int i=n;i>=1;--i){
    ans[i]=res;
    if(vis[ord[i]-1]){
      merge(ord[i]-1,ord[i]);
    }
    if(vis[ord[i]+1]){
      merge(ord[i]+1,ord[i]);
    }
    int f=find(ord[i]);
    res=max(res,sum[find(ord[i])]);
    vis[ord[i]]=1;
  }
  for(int i=1;i<=n;++i){
    cout<<ans[i]<<"\n";
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