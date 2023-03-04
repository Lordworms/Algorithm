#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
vector<vector<int>>dir={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
void solve()
{
  int n,m;
  cin>>n>>m;
  vector mp(n+1,vector<int>(m+1)),vis(mp),have(mp);
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=m;++j)
    {
        cin>>mp[i][j];
    }
  }
  int in_cnt=0,sx=-1,sy=-1,ans=0;
  auto check=[&](int i,int j)
  {
    return i>=1&&i<=n&&j>=1&&j<=m;
  };
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=m;++j)
    {
        if(mp[i][j]==1)continue;
        int cnt=0;
        for(int k=1;k<5;++k)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            if(!check(ni,nj))continue;
            cnt+=mp[ni][nj]<mp[i][j];
        }
        if(cnt==0)
        {
            ++in_cnt;
            sx=i,sy=j;
            have[i][j]=1;
        }
    }
  }
  if(in_cnt==0)
  {
    cout<<0<<'\n';
    return;
  }
  if(in_cnt>10)
  {
    cout<<2<<'\n';
    return;
  }
  auto cal=[&](int x,int y)
  {
    if(mp[x][y]==1)return 0;
    bool f=false;
    for(int i=1;i<5;++i)
    {
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(check(nx,ny)&&mp[nx][ny]<mp[x][y])
        {
            f=true;
            break;
        }
    }
    if(f&&have[x][y])return 1;
    if(!f&&!have[x][y])return -1;//because we deal with a wrong point need to balace 1
    return 0;
  };
  auto try_one=[&](int x,int y)
  {
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(vis[i][j])continue;
            int now_cnt=0;
            swap(mp[i][j],mp[x][y]);
            for(int k=0;k<5;++k)
            {
                int ni=i+dir[k][0],nj=j+dir[k][1];
                if(check(ni,nj))now_cnt+=cal(ni,nj);
            }
            for(int k=0;k<5;++k)
            {
                int nx=x+dir[k][0],ny=y+dir[k][1];
                if(check(nx,ny)&&abs(nx-i)+abs(ny-j)>1)now_cnt+=cal(nx,ny);
            }
            if(now_cnt==in_cnt)++ans;
            swap(mp[i][j],mp[x][y]);
        }
    }
  };
  for(int i=0;i<5;++i)
  {
    int nx=sx+dir[i][0],ny=sy+dir[i][1];
    if(check(nx,ny))
    {
        vis[nx][ny]=1;
        try_one(nx,ny);
    }
  }
  if(ans)
  {
    cout<<1<<' '<<ans<<'\n';
  }
  else
  {
    cout<<2<<'\n';
  }
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