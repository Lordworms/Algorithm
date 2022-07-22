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
//算的是x加的也是x
int EXCRT(vector<int>arr,vector<int>r)
{
   auto quick_mul=[](int a,int b,int mod)
   {
        int ans=0;
        while(b)
        {
            if(b&1)ans=(ans+a%mod)%mod;
            b>>=1;
            a=(a+a)%mod;
        }
        return ans;
   };
   auto lcm=[](int n,int m)
   {
        int x,y,g=exgcd(n,m,x,y);
        return n/g*m;
   };
   int ans=arr[0],M=r[0],n=arr.size();
    //x=arr[1](mod r[1]) x=arr[2](mod r[2])
    //x=r[1]*x+arr[1]=r[2]*y+arr[2]
    //r[1]*x-r[2]*y=arr[2]-arr[1]
    //x=(x*(arr[2]-arr[1])/gcd(arr[2]-arr[1])+r[2]/gcd[r[1],r[2]])%(r[2]/gcd(r[1],r[2]))即可
    //M=lcm(r[1],r[2])

    //x=a*r[i]+arr[i]=b*M+ans
    //b*M-a*r[i]=arr[i]-ans;
    //fac=(arr[i]-ans)/gcd(M,r[i]);
    //b*=fac; ans+=b*M
    //M=lcm(M,r[i])
   int x,y;
   for(int i=1;i<n;++i)
   {
      int C=(arr[i]-ans%r[i]+r[i])%r[i];
      int g=exgcd(M,r[i],x,y);
      if(C%g)return -1; 
      x=quick_mul(x,C/g,r[i]);
      y=r[i]/g;  
      x=(x%y+y)%y;
      ans+=x*M;//这里不需要mod
      M=lcm(M,r[i]);
      ans=(ans+M)%M;//已经合并了，所以需要继续弄
   }
   return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}