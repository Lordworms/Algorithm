/*
    every metaset consists two sets and share a common card

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector cards(n+1,vector<int>(k+1,0));
  auto check=[&](int a,int b,int c)
  {
    for(int i=1;i<=k;++i)
    {
        if((cards[a][i]+cards[b][i]+cards[c][i])%3)return false;
    }
    return true;
  };
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=k;++j)
    {
        cin>>cards[i][j];
    }
  }
  vector<int>num(n+1,0);
  for(int i=1;i<=n;++i)
  {
    for(int j=i+1;j<=n;++j)
    {
        for(int k=j+1;k<=n;++k)
        {
            if(check(i,j,k))
            {
                ++num[i];
                ++num[j];
                ++num[k];
            }
        }
    }
  }
  ll ans=0;
  for(int i=1;i<=n;++i)
  {
    ans+=(num[i]-1)*num[i]/2;
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