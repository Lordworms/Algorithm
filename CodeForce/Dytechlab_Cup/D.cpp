/*
题意：
    给你n个点m条边，你每次可以把链接(u,v)的边i变成(u,t),其中，t是直接和v相连的一条边，求从1到n的最小代价
题解：
    我们总是可以把1和n链接起来,另dis[u][v]为从u到v经过的点的数量
    连接的方式有两种
    1.当前使用i-j这条边，这条边是目前最小的
    那么就1-i-j-n
    2.当前选用i-j这条边，但是换一个中转点
    1-x-j-x-n 建设x-j这条路花了d[u][k]+1的代价
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1e9+10;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<ll>>dis(n,vector<ll>(n,INF));
    vector<vector<ll>>w(n,vector<ll>(n,INF));
    for(int i=0;i<n;++i)dis[i][i]=w[i][i]=0;
    int x,y;
    ll k;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>k;
        --x,--y;
        w[x][y]=min(w[x][y],k);
        w[y][x]=min(w[y][x],k);
        dis[x][y]=dis[y][x]=1;
    }
    for(int k=0;k<n;++k)
    {
        for(int j=0;j<n;++j)
        {
            for(int i=0;i<n;++i)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
   
    ll ans=1e18,now;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i!=j&&w[i][j]!=INF)
            {   
                now=w[i][j]*(dis[0][i]+1+dis[j][n-1]);
                ans=min(ans,now);
            for(int k=0;k<n;++k)
            {
                now=w[i][j]*(dis[0][k]+dis[k][n-1]+1+dis[k][i]+1);
                ans=min(ans,now);
            }
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}