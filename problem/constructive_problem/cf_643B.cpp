#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k,a,b,c,d;
  cin>>n>>k>>a>>b>>c>>d;
  if(k<n+1||n==4){
    cout<<-1<<'\n';
  }
  else{
    vector<int>vis(n+1);
    vis[a]=vis[b]=vis[c]=vis[d]=1;
    cout<<a<<' '<<c<<' ';
    for(int i=1;i<=n;++i){
        if(!vis[i])cout<<i<<' ';
    }
    cout<<d<<' '<<b<<'\n';
    cout<<c<<' '<<a<<' ';
    for(int i=1;i<=n;++i){
        if(!vis[i])cout<<i<<' ';
    }
    cout<<b<<' '<<d<<'\n';
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