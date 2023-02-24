#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m,d;
  cin>>n>>m>>d;
  vector<int>pos(n+1);
  vector<int>a(m+1);

  for(int i=1;i<=n;++i)
  {
    int x;
    cin>>x;
    pos[x]=i;
  }
  int ans=INT_MAX;
  for(int i=1;i<=m;++i)cin>>a[i];
  for(int i=1;i<=m-1;++i)
  {
    if(!(pos[a[i]]<pos[a[i+1]]&&pos[a[i+1]]<=pos[a[i]]+d))
    {
        ans=0;
        break;
    }
    int d1=pos[a[i+1]]-pos[a[i]];
    int d2=d+(pos[a[i]]-pos[a[i+1]])+1;
    if(d+2>n)
    {
        ans=min(ans,d1);
    }
    else
    {
        ans=min(ans,min(d1,d2));
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