#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node{int id,val;};
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  vector<int>deg(n,0),x(m,0),y(m,0);
  for(int i=0;i<m;++i)
  {
    cin>>x[i]>>y[i];
    --x[i],--y[i];
    deg[x[i]]++;
    deg[y[i]]++;
  }
  int ans=INT_MAX;
  if(m%2)
  {
    for(int i=0;i<n;++i)
    {
        if(deg[i]%2)
        {
            ans=min(a[i],ans);
        }
    }
    for(int i=0;i<m;++i)
    {
        if(deg[x[i]]%2==0&&deg[y[i]]%2==0)
        {
            ans=min(ans,a[x[i]]+a[y[i]]);
        }
    }
    cout<<ans<<'\n';
  }
  else
  {
    cout<<0<<'\n';
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