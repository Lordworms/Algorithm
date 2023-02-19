#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m;
  cin>>n>>m;
  int len1=1,len2=1;
  for(int i=7;i<n;i*=7)len1++;
  for(int i=7;i<m;i*=7)len2++;
  if(len1+len2>7)
  {
    cout<<0<<'\n';
    return;
  }
  vector<int>vis(10);
  auto check=[&](int x,int len)
  {
    int tot=0;
    while(x)
    {
        if(vis[x%7])
        {
            return false;
        }
        vis[x%7]=1,x/=7;
        ++tot;
    }
    for(int i=tot;i<len;++i)
    {
        if(vis[0])return false;
        vis[0]=1;
    }
    return true;
  };
  int ans=0;
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
    {
        fill(vis.begin(),vis.end(),0);
        if(i==j||!check(i,len1)||!check(j,len2))continue;
        ++ans;
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}