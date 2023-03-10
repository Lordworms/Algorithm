#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
const int MOD=1e9+7;
void solve(){
  int n,m;cin>>n>>m;
  auto check=[&](int x,int y){
    return x>=1&&x<=n&&y>=1&y<=m;
  };
  vector<vector<char>>mp(n+1,vector<char>(m+1));
  vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
  vector<vector<int>>dis(n+1,vector<int>(m+1));
  auto check_char=[&](int x,int y,int tx,int ty){
    return mp[x][y]=='D'&&mp[tx][ty]=='I'||mp[x][y]=='I'&&mp[tx][ty]=='M'||mp[x][y]=='M'&&mp[tx][ty]=='A'||mp[x][y]=='A'&&mp[tx][ty]=='D';
  };
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
        cin>>mp[i][j];
    }
  }
  int ans=0;
  function<void(int,int)>dfs=[&](int x,int y){
    if(dis[x][y])return;
    vis[x][y]=1;
    dis[x][y]=1;
    for(int i=0;i<4;++i){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(!check(tx,ty)||!check_char(x,y,tx,ty))continue;
        if(vis[tx][ty]){
            cout<<"Poor Inna!\n";
            exit(0);
        }
        dfs(tx,ty);
        dis[x][y]=max(dis[x][y],dis[tx][ty]+1);
    }
    vis[x][y]=0;
  };
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
        if(mp[i][j]=='D'&&!vis[i][j]){//did not appear in other situation
            dfs(i,j);
            ans=max(dis[i][j],ans);
        }
    }
  }
  ans/=4;
  if(ans==0){
    cout<<"Poor Dima!\n";
  }else{
    cout<<ans<<'\n';
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