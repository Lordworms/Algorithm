/*
题意：
题解：枚举可以得到最多就7个值，所以枚举一下
     我们令F(d)为选i个数且其gcd为d的倍数的情况
     f(d)为gcd为d的情况
     F(d)=
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=300010;
const int mod=1e9+7;
int n,k;
int cnt[MAXN],inv[MAXN],fac[MAXN],mu[MAXN],prim[MAXN];
bool flag[MAXN];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int quick_pow(int base,int exp){int ans=1;while(exp){if(exp&1)ans=ans*base%mod;exp>>=1,base=base*base%mod;}return ans;}
void init(int n)
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=n;++i)fac[i]=fac[i-1]*i%mod;
    inv[n]=quick_pow(fac[n],mod-2);
    for(int i=n-1;i>=0;--i)inv[i]=inv[i+1]*(i+1)%mod;
    mu[1]=1;int cnt=0;
    for(int i=2;i<=n;++i)
    {
        if(!flag[i])prim[cnt++]=i,mu[i]=-1;
        for(int j=0;j<cnt&&i*prim[j]<=n;++j)
        {
            flag[i*prim[j]]=true;
            if(i%prim[j]==0)
            {
                flag[i*prim[j]]=true;
                break;   
            }
            mu[i*prim[j]]=-mu[i];
        }
    }
}
int C(int n,int m)
{
    if(m<0||m>n)return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init(MAXN-10);
  cin>>n;
  int x,g;
  for(int i=0;i<n;++i){
    cin>>x;
    cnt[x]++;
    g=i==0?x:gcd(g,x);
  }
  if(g>1){cout<<-1<<endl;return 0;}
  for(int i=1;i<MAXN;++i)
  {
	for(int j=2*i;j<MAXN;j+=i)
	{
		cnt[i]+=cnt[j];
	}
  }
  for(int k=1;k<=min((int)7,n);++k)
  {
     int amt=0;
     for(int i=1;i<MAXN;++i)
     {
        if(cnt[i]>=k)
        {
            (amt+=mu[i]*C(cnt[i],k)%mod)%=mod;
        }
     }
    if(amt!=0){cout<<k<<endl;return 0;}
  }
  return 0;
}