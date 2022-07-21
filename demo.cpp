/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
      while(x<0)x+=(r[i]/g); 
      x=quick_mul(x,C/g,r[i]);
      ans+=x*M;//这里不需要mod
      M=lcm(M,r[i]);
      ans=(ans+M)%M;//已经合并了，所以需要继续弄
   }
   return ans;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>arr,r;
  int n;
  cin>>n;arr.resize(n),r.resize(n);
  for(int i=0;i<n;++i)cin>>r[i]>>arr[i];
  cout<<EXCRT(arr,r)<<endl;
  return 0;
}
