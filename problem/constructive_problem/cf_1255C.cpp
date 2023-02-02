#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>deg(n+1);
  vector<set<int>>E(n+1);
  auto add=[&](int now,int a,int b)
  {
    E[now].insert(a);
    E[now].insert(b);
  };
  for(int i=0;i<n-2;++i)
  {
    int a,b,c;
    cin>>a>>b>>c;
    deg[a]++;
    deg[b]++;
    deg[c]++;
    add(a,b,c);
    add(b,c,a);
    add(c,a,b);
  }
  int a=0,b=0;
  for(int i=1;i<=n;++i)
  {
    if(deg[i]==1)
    {
        if(a==0)
        {
            a=i;
        }
        else
        {
            deg[i]=3;
        }
    }
  }
  for(int v:E[a])
  {
    if(deg[v]==2)
    {
        b=v;
    }
  }
  for(int i=1;i<=n;++i)
  {
    if(deg[i]==2&&i!=b)
    {
        deg[i]++;
    }
  }
  queue<int>q;
  q.push(a);
  int i=0;
  vector<bool>vis(n+1,false);
  vector<int>ans;
  while(!q.empty())
  {
    int now=q.front();
    q.pop();
    vis[now]=true;
    cout<<now<<' ';
    for(int v:E[now])
    {
       if(!vis[v])
       {
            deg[v]--;
            if(deg[v]==1)
            {
                vis[v]=true;
                q.push(v);
            }
       }
    }
  }
  cout<<'\n';
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