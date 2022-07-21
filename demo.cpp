/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
int quick_pow(int x,int exp,int mod)
{
    int ans=1;
    while(exp)
    {
       if(exp&1)ans=ans*x%mod;
       x=x*x%mod;
       exp>>=1; 
    }
    return ans%mod;
}
int CRT(vector<int>arr,vector<int>r)
{
    int re=1,ans=0;
    for(int num:r)re*=num;
    for(int i=0;i<arr.size();++i)
    {
        int m=re/r[i];
        ans=(ans+quick_pow(m,r[i]-2,re)*m*arr[i])%re;
    }
    return ans%re;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin>>T;
  vector<int>arr(T),r(T);
  for(int i=0;i<T;++i)cin>>r[i]>>arr[i];
  cout<<CRT(arr,r)<<endl;
  return 0;
}