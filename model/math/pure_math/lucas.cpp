/*
用于求解c(n,m) mod p
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
long long inv[MAXN],fac[MAXN];
void init(int n,int p)
{
    auto quick_pow=[&](long long b,long long exp){
        long long ans=1;
        while(exp)
        {
            if(exp&1)ans=ans*b%p;
            b=b*b%p;
            exp>>=1;
        }
        return ans%p;
    };
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%p,inv[i]=quick_pow(fac[i],p-2);
}
long long C(int n,int m,int p)
{
    return fac[n]*inv[m]%p*inv[m-n]%p;
}
long long lucas(long long n,long long m,long long p)
{
    if(m==0)return 1;
    return C(n%p,m%p,p)*lucas(n/p,m/p,p);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}