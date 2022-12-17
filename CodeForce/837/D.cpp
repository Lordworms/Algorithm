#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2003;
int dp[MAXN][MAXN];
int nxt[MAXN][MAXN];//nxt[x][y] means next x nxt[y][x] means next y
vector<vector<int>>G;
string s;
int n;
void init(int st,int fa,int end)
{
  nxt[st][end]=fa;
  for(auto& v:G[st])
  {
    if(v==fa)continue;
    init(v,st,end);
  }
}
int dfs(int i,int j)
{
  if(i==j)return 1;
  if(nxt[i][j]==j)return 1+(s[i]==s[j]);
  if(dp[i][j]!=-1)return dp[i][j];
  int& ans=dp[i][j];
  if(s[i]==s[j])
  {
    ans=dfs(nxt[i][j],nxt[j][i])+2;
  }
  else
  {
    ans=max(dfs(nxt[i][j],j),dfs(nxt[j][i],i));
  }
  return dp[j][i]=ans;
}
void solve()
{
  cin>>n>>s;
  G.clear();
  G.resize(n);
  for(int i=0;i<n-1;++i)
  {
    int u,v;
    cin>>u>>v;
    u--,v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      dp[i][j]=nxt[i][j]=-1;
  for(int i=0;i<n;++i)init(i,-1,i);
  int ans=1;
  for(int i=0;i<n;++i)
  {
    for(int j=i+1;j<n;++j)
    {
      ans=max(ans,dfs(i,j));
    }
  }
  cout<<ans<<'\n';
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}