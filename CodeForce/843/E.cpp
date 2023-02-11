/*
    两种操作，a类和b类，a将末尾元素减少1，b将末尾元素增加1
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll a=0,b=0;
  int n;
  cin>>n;
  vector<ll>ar(n);
  ll ans=0;
  for(int i=0;i<n;++i)cin>>ar[i];
  for(int i=0;i<n;++i)
  {
    if(ar[i]>0)
    {
        ll t=min(a,ar[i]);
        ar[i]-=t;
        a-=t;
        ans+=ar[i];
        b+=t+ar[i];
    }
    else
    {
        ar[i]=-ar[i];
        ll t=min(b,ar[i]);
        b-=t;
        ar[i]-=t;
        ans+=ar[i];
        a+=t+ar[i];
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