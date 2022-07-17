/*
题意：
    Nick is attracted by everything unconventional. He doesn't like decimal number system any more, 
    and he decided to study other number systems. A number system with base b caught his attention. 
    Before he starts studying it, he wants to write in his notepad all the numbers of length n without 
    leading zeros in this number system. Each page in Nick's notepad has enough space for c numbers exactly.
    Nick writes every suitable number only once, starting with the first clean page and leaving no clean spaces.
    Nick never writes number 0 as he has unpleasant memories about zero divide.
    Would you help Nick find out how many numbers will be written on the last page.
题解：
    拓展欧拉板子题
    求b^(n-1)*(b-1)modc的值
    注意b和c会爆int，需要先用string接受然后重新弄
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int quick_pow(int base,int exp,int mod)
{
    base%=mod;
    int ans=1;
    while(exp)
    {
        if(exp&1)ans=ans*base%mod;
        exp>>=1;
        base=1ll*base*base%mod;    
    }
    return ans;
}
int erular(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
           ans=ans/i*(i-1); 
           while(x%i==0)x/=i;
        }
    }
    if(x!=1)ans=ans/x*(x-1);
    return ans;
}
int getInt(string s,int mod)
{
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        ans=((10ll*ans)%mod)+s[i]-'0';
    }
    return ans;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string B,N;
  int c;
  cin>>B>>N>>c;
  int x=erular(c);
  int b=getInt(B,c);
  int n=0;
  bool flag=false;
  for(int i=0;i<N.size();++i)
  {
    n=(n*10ll+N[i]-'0');
    if(n>=x)flag=true;
    n%=x;
  }
  
  n--;
  if(flag)n+=x;
  int ans=(b-1)*quick_pow(b,n,c)%c;
  if(!ans)ans=c;
  cout<<ans<<endl;
  return 0;
}