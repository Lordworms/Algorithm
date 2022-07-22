/*
多学习
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6+10;
int row1[MAXN],row2[MAXN],dp[MAXN];
int lim;
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
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int EXCRT(int a1,int a2,int r1,int r2)
{
    int x,y;
    int g=exgcd(r1,r2,x,y);
    if((a2-a1)%g)return -1;
    y=r2/g;
    x*=(a2-a1)/g;
    x=(x%y+y)%y;
    a1+=x*r1;
    return a1;
}
bool check(int mid,int k,int lc)//在1-mid的范围内，查找哪些数是满足情况的
{
    int ans=0;
    for(int i=1;i<=lim;++i)
    {
        if(!dp[i])continue;
        if(mid>=dp[i])//如果当前两者相等的时间点
        {
            ans+=(mid-dp[i])/lc+1;
        }
        if(mid-ans<k)return false;//不相等的次数小于k,返回错误
    }
    return mid-ans>=k;//不相等的次数大于k，会生气
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k,x;
  cin>>n>>m>>k;
  for(int i=1;i<=n;++i)cin>>x,row1[x]=i;
  for(int i=1;i<=m;++i)cin>>x,row2[x]=i;
  lim=2*max(n,m);
  int lcm=m/gcd(m,n)*n;
  int g=gcd(m,n);
  for(int i=1;i<=lim;++i)
  {
    if(!row1[i]||!row2[i]||abs(row2[i]-row1[i])%g)continue;
    dp[i]=EXCRT(row1[i],row2[i],n,m);
  }
  int l=0,r=1e18,mid;
  while(l<=r)
  {
    m=(l+r)>>1;
    if(check(m,k,lcm))r=m-1;
    else l=m+1;
  }
  cout<<l<<endl;
  return 0;
}