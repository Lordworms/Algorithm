#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  int l=1,r=1,ans=-1,cnt=0,maxl,maxr;
  while(r<=n)
  {
    if(a[r]!=1)
    {
        if(cnt<k)
        {
            ++cnt;
        }
        else
        {
            while(a[l++]==1);
        }
    }
    if(r-l+1>ans)
    {
        maxl=l,maxr=r;
    }
    ans=max(ans,r-l+1);
    ++r;
  }
  cout<<ans<<'\n';
  for(int i=1;i<=n;++i)
  {
    if(i>=maxl&&i<=maxr)
    {
        a[i]=1;
    }
    cout<<a[i]<<" \n"[i==n];
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