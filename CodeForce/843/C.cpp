/*

    1. if there is a bit in n that is 0, but in x it is 1, then it is impossible
    then consider each bit in x and n
        1. xb=0, nb=0 whatever m is ok
        2. xb=1  nb=0 l=min(l, (n/(1<<i)+1)*())
        3. xb=1  nb=1 

    we use l,r to represent the solution domain

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll n,x;
  cin>>n>>x;
  bitset<64>a(n),b(x);
  ll l=n,r=5e18;
  for(int i=63;i>=0;--i)
  {
    if(a[i]==0&&b[i]==1)
    {
        cout<<-1<<'\n';
        return;
    }
    else if(a[i]==0&&b[i]==0)
    {
        continue;
    }
    else if(a[i]==1&&b[i]==0)
    {
        l=max(l,(n/(1ll<<i)+1)<<i);
    }
    else if(a[i]==1&&b[i]==1)
    {
        r=min(r,((n/(1ll<<i)+1)<<i)-1);
    }
  }
  cout<<(l<=r?l:-1)<<'\n';
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