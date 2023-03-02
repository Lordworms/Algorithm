#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int x;
  cin>>x;
  int a=0,b=0;
  int cur=1;
  int base=1;
  while(x)
  {
    int rem=x%10;
    if(cur)
    {
        a+=(rem/2+(rem%2==1))*base;
        b+=(rem/2)*base;
    }
    else
    {
        b+=(rem/2+(rem%2==1))*base;
        a+=(rem/2)*base;
    }
    x/=10;
    if(rem%2)cur^=1;
    base*=10;
  }
  cout<<a<<' '<<b<<'\n';
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