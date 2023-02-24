#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>E(n);
  vector<int>deg(n);
  vector<int>a(m),b(a);
  for(int i=0;i<m;++i)
  {
    int x,y;
    cin>>x>>y;
    --x,--y;
    E[x].push_back(y);
    deg[y]++;
    a[i]=x;
    b[i]=y;
  }
  queue<int>q;
  map<int,int>trace;
  int num=0;
  for(int i=0;i<n;++i)
  {
    if(!deg[i])
    {
      q.push(i);
      num++;
    }
  }
  int cnt=0;
  while(!q.empty())
  {
    if(num>1)
    {
      cout<<-1<<'\n';
      return;
    }
    auto x=q.front();
    q.pop();
    num--;
    for(auto v:E[x])
    {
      deg[v]--;
      if(!deg[v])
      {
        num++;
        q.push(v);
        trace[v]=x;
        ++cnt;
      }
    }
  }
  for(int i=0;i<m;++i)
  {
    if(trace[b[i]]==a[i])
    {
      --cnt;
      if(!cnt)
      {
        cout<<i+1<<'\n';
        return;
      }
    }
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