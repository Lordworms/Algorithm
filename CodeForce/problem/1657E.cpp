#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=1e3+5;
ll dp[N][N];
ll fac[N],inv[N];
int n,k;
ll qpow(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
void init()
{
   fac[0]=1;
   for(int i=1;i<=N;++i)fac[i]=fac[i-1]*i%mod;
   inv[N]=qpow(fac[N],mod-2);
   for(int i=N-1;i>=0;--i)inv[i]=(i+1)*inv[i+1]%mod;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   init();
   cin>>n>>k;
   dp[1][0]=1;
   for(int i=1;i<=n;++i)
   {
      for(int j=1;j<=k;++j)
      {
         for(int z=1;z<=i;++z)
         {
            ll a=dp[z][j-1]*fac[i-1]%mod*inv[z-1]%mod*inv[i-z]%mod;
            ll b=qpow(k-j+1,(z-1)*(i-z)+(i-z-1)*(i-z)/2);
            dp[i][j]=(dp[i][j]+a*b%mod)%mod;
            
         }
      }
   }
   cout<<dp[n][k]<<endl;
   return 0;
}
