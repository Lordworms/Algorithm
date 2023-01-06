#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int MAXN=4e5+10;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<string>mp(n);
  for(int i=0;i<n;++i)cin>>mp[i];
  deque<pii>q;
  vector pre(n+1,vector<pii>(m+1));
  vector dis(n+1,vector<int>(m+1,MAXN));
  auto check=[&](int x,int y)
  {
    if(x<0||x>=n||y<0||y>=m)return false;
    if(x>0&&mp[x-1][y]=='#')return false;
    if(x<n-1&&mp[x+1][y]=='#')return false;
    if(y>0&&mp[x][y-1]=='#')return false;
    if(y<m-1&&mp[x][y+1]=='#')return false;
    return true;
  };
  for(int i=0;i<n;++i)
  {
    if(mp[i][0]=='#')
    {
        q.push_back({i,0});
        dis[i][0]=0;
        continue;
    }
    if(check(i,0))
    {
        q.push_back({i,0});
        dis[i][0]=1;
    }
  }
  vector vis(n+1,vector<bool>(m+1,false));
  while(!q.empty())
  {
    auto [x,y]=q.front();
    q.pop_front();
    vis[x][y]=true;
    for(int i:{-1,1})
    {
        for(int j:{-1,1})
        {
            int nx=x+i,ny=y+j;
            if(check(nx,ny)&&dis[nx][ny]>dis[x][y]+(mp[nx][ny]!='#'))
            {
                dis[nx][ny]=dis[x][y]+(mp[nx][ny]!='#');
                pre[nx][ny]={x,y};
                if(mp[nx][ny]=='#')
                {
                    q.push_front({nx,ny});
                }
                else
                {
                    q.push_back({nx,ny});
                }
            }
        }
    }
  }
  ll ans=MAXN;
  int pos=-1;
  for(int i=0;i<n;++i)
  {
    if(dis[i][m-1]<ans)
    {
        ans=dis[i][m-1];
        pos=i;
    }
  }
  if(ans>=MAXN)
  {
    cout<<"NO"<<"\n";
    return;
  }
  cout<<"YES"<<'\n';
  int nx=pos,ny=m-1;
  while(1)
  {
    mp[nx][ny]='#';
    if(ny==0)break;
    auto [tx,ty]=pre[nx][ny];
    nx=tx;
    ny=ty;
  }
  for(int i=0;i<n;++i)
  {
    cout<<mp[i]<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}