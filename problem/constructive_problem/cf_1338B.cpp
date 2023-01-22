/*
    constructive problem
    first, if all path between leaves have even length

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector E(n,vector<int>(0));
  vector<int>deg(n,0);
  for(int i=0;i<n-1;++i)
  {
    int x,y;
    cin>>x>>y;
    --x,--y;
    E[x].push_back(y);
    E[y].push_back(x);
    ++deg[x];
    ++deg[y];
  }
  bool flag=false;
  function<void(int,int,int)>dfs=[&](int now,int fa,int dep)
  { 
    if(deg[now]==1&&dep%2==1)
    {
        flag=true;
        return;
    }
    for(auto nxt:E[now])
    {
        if(fa==nxt)continue;
        dfs(nxt,now,dep+1);
    }
  };
  for(int i=0;i<n;++i)
  {
    if(deg[i]==1)
    {
        dfs(i,-1,0);
        break;
    }
  }
  cout<<(flag?3:1)<<' ';
  int ans=n-1;
  for(int i=0;i<n;++i)
  {
    int cnt=0;
    if(deg[i]==1)continue;
    for(auto& v:E[i])
    {
        if(deg[v]==1)
        {
            ++cnt;
        }
    }
    if(cnt==0)continue;
    ans-=(cnt-1);
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}