/*
扩展gcd板子，注意的是需要使用y来遍历，因为平局的分少于赢的分
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,w,d;
int exgcd(int a,int b,int& x,int& y)
{   
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>p>>w>>d;
  int x,y;
  //xw+dy=p
  int g=exgcd(w,d,x,y);
  w/=g;
  int ans=(y%w)*(p/g%w)%w;//overflow
  while(ans<0)ans+=w;
  w*=g;
  y=ans;
  x=(p-d*y)/w;
  if(p%g!=0)x=-1;
  if(x<0||x+y>n)
  {
    cout<<-1<<endl;
    return 0;
  }
  cout<<x<<" "<<y<<" "<<n-x-y<<endl;
  return 0;
}