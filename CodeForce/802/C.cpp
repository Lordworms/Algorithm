/*
    Three operations in total
    let b be the difference array of original array
    so the original operations would be 
    1.a[1->i]-=1 -> b[1]+=1 b[i+1]+=1
    2.a[i->n]-=1 -> b[i]-=1
    3.a[1->n]+=1 -> b[1]+=1

    we could iterate over [2->n] then deal with b[1]
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1),b(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i)b[i]=a[i]-a[i-1];
  int ans=0;
  for(int i=2;i<=n;++i)
  {
    if(b[i]>0)
    {
        ans+=b[i];
    }
    else
    {
        ans+=abs(b[i]);
        b[1]-=abs(b[i]);
    }
  }
  ans+=abs(b[1]);
  cout<<ans<<'\n';
  return;
}
signed main()
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