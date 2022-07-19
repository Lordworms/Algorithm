/*
题解：
  通过这题完全弄懂这个平面扩展点的问题
  一个点(x,y)如果把它展开到无限的矩形平面，那么对应的坐标是啥呢？2kn+-x/2tm+-y 我们连接这两个等式，然后我们用exgcd算出解就可以了
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,lim;
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
int get(int dx,int dy)
{
  int x,y;
  int g=exgcd(2*n,2*m,x,y);
  if((dy-dx)%g!=0)return INT_MAX;
  x*=(dy-dx)/g;
  y*=(dy-dx)/g;
  int m=2*n/g;
  x=(x%m+m+m-1)%m+1;
  int ans=x*2*n+dx;
  if(ans<0)return INT_MAX;
  return ans;
}
int solve(int x,int y)
{
  int ans=INT_MAX;
  ans=min(get(x,y),ans);
  ans=min(get(-x,y),ans);
  ans=min(get(x,-y),ans);
  ans=min(get(-x,-y),ans);
  if(ans>lim)ans=INT_MAX;
  if(ans==INT_MAX)return -1;
  return ans;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m>>k;
  int x,y;
  lim=n/exgcd(n,m,x,y)*m;
  int q,t,g;
  while(k--)
  {
    cin>>x>>y;
    cout<<solve(x,y)<<endl;
  }  
  return 0;
}