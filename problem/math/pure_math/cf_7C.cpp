/*
    exgcd板子，没啥好说的
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,x,y,c;
int exgcd(int a,int b,int& x,int& y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>a>>b>>c;
  exgcd(a,b,x,y);
  int sum=x*a+y*b;
  if(-c%sum==0)
  {
    x*=(-c/sum);
    y*=(-c/sum);
    cout<<x<<" "<<y<<endl;
  }
  else
  {
    cout<<-1<<endl;
  }
  return 0;
}