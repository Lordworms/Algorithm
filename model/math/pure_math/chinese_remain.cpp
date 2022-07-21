/*
中国剩余定理板子
注意中国剩余定理只可以用exgcd来求，因为我们要判定有没有解
中国剩余定理要求我们的每个模数都是质数且不相同，那么我们应该怎么应对更一般的情况呢

*/
#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int& x,int& y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(a,b,y,x);
    y-=(a/b)*x;
    return d;
}
int CRT(vector<int>arr,vector<int>r)
{
    int re=1,ans=0;
    for(int num:r)re*=num;
    for(int i=0;i<arr.size();++i)
    {
        int m=re/r[i],y,b;
        exgcd(m,r[i],b,y);
        ans=(ans+m*b*arr[i]%re)%re;
    }
    return ans;
}
int EXCRT(vector<int>arr,vector<int>r)
{
   auto quick_mul=[](int a,int b,int mod)
   {
        int ans=0;
        while(b)
        {
            if(b&1)ans=(ans+a%mod)%mod;
            b>>=1;
            a=a*a%mod;
        }
        return ans;
   };
   auto lcm=[](int n,int m)
   {
        int x,y;
        return n/exgcd(n,m,x,y)*m;
   };
   int ans=r[0],M=arr[0],n=arr.size();
   for(int i=1;i<n;++i)
   {
        
   }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}