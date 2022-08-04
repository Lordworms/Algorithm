#pragma GCC optimize(2)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll inff = 0x3f3f3f3f3f3f3f3f;
#define FOR(i,a,b) for(int i(a);i<=(b);++i)
#define FOL(i,a,b) for(int i(a);i>=(b);--i)
#define REW(a,b) memset(a,b,sizeof(a))
#define inf int(0x3f3f3f3f)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define mod ll(1e9+7)
#define pb push_back
#define eps 1e-6
#define lc d<<1
#define rc d<<1|1
#define Pll pair<ll,ll>
#define P pair<int,int>
#define pi acos(-1)
int n,a,g,cnt[300008],mu[300008],vis[300008],pr[300008],tot;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
ll jc[300008],inv[300008];
ll gmod(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void mobious(int n)
{
    jc[0]=jc[1]=1;
    FOR(i,2,n) jc[i]=jc[i-1]*(ll)i%mod;
    inv[n]=gmod(jc[n],mod-2);
    FOL(i,n-1,0) inv[i]=inv[i+1]*(i+1)%mod;
    mu[1]=1;
    FOR(i,2,n)
    {
        if(!vis[i]) pr[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&pr[j]*i<=n;j++)
        {
            int k=pr[j]*i;vis[k]=1;
            if(i%pr[j]==0){mu[k]=0;break;}
            else mu[k]=-mu[i];
        }
    }
}
ll C(int n,int m){return (jc[n]*inv[m]%mod)*inv[n-m]%mod;}
int main()
{
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    FOR(i,1,n)  si(a),g=(i==1)?a:gcd(a,g),cnt[a]++;
    if(g>1) {puts("-1");return 0;}
    FOR(i,1,300000)
     for(int j=i+i;j<=300000;j+=i)  cnt[i]+=cnt[j];
    mobious(300000);
    FOR(i,1,min(7,n))
    {
        int qw=0;
        //cout<<i<<endl;
        for(int j=1;j<=300000;j++) if(cnt[j]>=i)
        {
            //if(i==3) cout<<j<<endl;
            qw=(qw+mu[j]*C(cnt[j],i))%mod;
        }
        //cout<<qw<<endl;
        if(qw!=0) {printf("%d\n",i);return 0;}
    }
    return 0;
}