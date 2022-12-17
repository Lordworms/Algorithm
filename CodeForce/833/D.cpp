/*
gcd(x,2^30)=lowbit(x)
assume that c=a|b  if c==x such that a|x=b|x=c
notice that x<2^60
so we have 30 extra bits to adjust
let x=m*2^30+c
so m*2^30-n*d=-c
the function has a solution only if c%gcd(2^30,d)==0
we could get the answer using gcd
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lb(x) x&-x
int exgcd(int a,int b,int& x,int& y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
void solve()
{
    int a,b,c,d,g,m,n;
    cin>>a>>b>>d;
    c=a|b;
    g=exgcd(1<<30,d,m,n);
    if(c%g)
    {
        cout<<-1<<'\n';
        return;
    }
    m=c/g*(d-m)%d;
    auto ans=((m<<30)|c);
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