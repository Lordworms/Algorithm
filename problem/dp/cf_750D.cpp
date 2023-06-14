#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=310;
const int MAXM=33;
int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
int mp[MAXN][MAXN];
int dp[MAXN][MAXN][MAXM][8];
struct node {
  int x,y,depth,dir;  
};
void solve(){
  int n;
  cin>>n;
  vector<int>t(n+1);
  for(int i=1;i<=n;++i)cin>>t[i];
  queue<node>q;
  q.push({152,152,1,2});
  while(!q.empty()){
    auto cur=q.front();
    q.pop();
    if(cur.depth>n||dp[cur.x][cur.y][cur.depth][cur.dir]==1)continue;
    dp[cur.x][cur.y][cur.depth][cur.dir]=1;
    for(int i=1;i<=t[cur.depth];++i){
        cur.x+=dx[cur.dir];
        cur.y+=dy[cur.dir];
        mp[cur.x][cur.y]=1;
    }
    q.push({cur.x,cur.y,cur.depth+1,(cur.dir+1)%8});
    q.push({cur.x,cur.y,cur.depth+1,(cur.dir+7)%8});
  }
  int ans=0;
  for(int i=1;i<MAXN;++i){
    for(int j=1;j<MAXN;++j){
        if(mp[i][j]){
            ++ans;
        }
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