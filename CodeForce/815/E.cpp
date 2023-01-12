/*
    if now<k then we just print k-now
    if now>k, we could prove that we could limit the answer in [1,2]
    easy to find if we choose a square from leftup point and another square from (l+1,l+1)
    so the problem has changed into another problem which is that
    how to find a sqare that could make 
    pre: 2-D 差分
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct Border
{
    const int INF=0x3f3f3f3f;
    int maxx,maxy,minx,miny;
    Border()
    {
        maxx=maxy=-INF;
        minx=miny=INF;
    }
};
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<bool>vis(n*n,false);
  vector<Border>b(n*n);
  int cnt=0;
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=n;++j)
    {
        int x;
        cin>>x;
        --x;
        if(!vis[x])++cnt;
        vis[x]=true;
        b[x].maxx=max(i,b[x].maxx);
        b[x].minx=min(i,b[x].minx);
        b[x].maxy=max(j,b[x].maxy);
        b[x].miny=min(j,b[x].miny);
    }
  }
  if(cnt<=k)
  {
    cout<<k-cnt<<'\n';
    return;
  }
  vector s(n+2,vector<int>(n+2));
  for(int len=0;len<n;++len)
  {
    for(int i=1;i<=n-len;++i)
    {
        fill(s[i].begin(),s[i].end(),0);
    }
    for(int i=0;i<n*n;++i)
    {
        if(!vis[i]||b[i].maxx-b[i].minx>len||b[i].maxy-b[i].miny>len)continue;
        int minx=max(b[i].maxx-len,1);
        int maxx=b[i].minx;
        int miny=max(b[i].maxy-len,1);
        int maxy=b[i].miny;
        ++s[minx][miny];
        --s[maxx+1][miny];
        --s[minx][maxy+1];
        ++s[maxx+1][maxy+1];
    }
    for(int i=1;i<=n-len;++i)
    {
        for(int j=1;j<=n-len;++j)
        {
            s[i][j]+=s[i][j-1];
        }
    }
    for(int i=1;i<=n-len;++i)
    {
        for(int j=1;j<=n-len;++j)
        {
            s[i][j]+=s[i-1][j];
            if(cnt-s[i][j]==k||cnt-s[i][j]==k-1)
            {
                cout<<1<<'\n';
                return;
            }
        }
    }
  }
  cout<<2<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}