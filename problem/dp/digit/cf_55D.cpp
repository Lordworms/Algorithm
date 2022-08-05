/*
题意：求l,r间有多少数能够被每一位上的数整除
题解：数位DP+记忆化搜索
    前置：任何一个数可以表示为2520*k+num'=num
    dp[pos][num][lcm]表示当前枚举到了第pos位，之前的
*/
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
const int MOD=2520;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int LCM(int a,int b){return a/gcd(a,b)*b;}
ll l,r;
ll dp[20][50][MOD+1];//第二维存的是lcm的前缀，但是只会有48种，所以多了
int h[MOD+10];
int dig[20];
ll dfs(int pos,int num,int lcm,bool flag)//flag用来判断是不是要开始计数了
{   
    if(pos<0)return num%lcm==0;
    if(!flag&&dp[pos][h[lcm]][num]!=-1)return dp[pos][h[lcm]][num];
    ll ans=0,end=flag?dig[pos]:9;
    for(int i=0;i<=end;++i)
    {
        ans+=dfs(pos-1,(num*10+i)%MOD,!i?lcm:LCM(lcm,i),flag&&i==end);
    }
    if(!flag)dp[pos][h[lcm]][num]=ans;
    return ans;
}   
ll solve(ll len)
{   
    int cnt=0;
    while(len)
    {
        dig[cnt++]=len%10;
        len/=10;
    }
    return dfs(cnt-1,0,1,true);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int cnt=0;
  int T;cin>>T;
  for(int i=1;i<=MOD;++i)if(MOD%i==0)h[i]=++cnt;
   memset(dp,-1,sizeof(dp));
  while(T--)
  {
    cin>>l>>r;
    cout<<solve(r)-solve(l-1)<<endl;
  }
  return 0;
}