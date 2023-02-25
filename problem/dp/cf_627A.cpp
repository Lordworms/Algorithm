/*
    a+b=a^b+(a&b)<<1
    异或是不进位的加法
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll s,x;
  cin>>s>>x;
  ll ad=((s-x)>>1);
  bool flag=false;
  if((s-x)%2||s<x)
  {
    flag=true;
  }
  ll ans=1;
  for(int i=0;i<60;++i)
  {
    if((x>>i)&1)//(x>>i)&1==0确定只有一种
    {
        if((ad>>i)&1)
        {
            flag=true;
            break;
        }
        ans<<=1;
    }
  }
  if(x==s)ans-=2;//(0,s)(s,0)
  cout<<(flag?0:ans)<<'\n';

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