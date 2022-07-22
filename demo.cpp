#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<ctime>
#define iss ios::sync_with_stdio(false)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int mod=1e9+7;
const int MAXN=1e6+5;
const int N=1e5+10;
int n,m;
int p1[MAXN],p2[MAXN];
ll dp[MAXN];
ll gcd(ll a,ll b) {
    return b == 0 ? a : gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b == 0) {
        x = 1,y = 0;
        return a;
    }
    else {
        ll res = exgcd(b,a%b,x,y);
        ll t = x;
        x = y;
        y = t - a / b * y;
        return res;
    }
}
ll excrt(ll m1,ll m2,ll a1,ll a2) {
    ll x,y,c,g;
    c = a2 - a1;
    g = exgcd(m1,m2,x,y);
    x = x * c / g;
    y = m2 / g;
    x = (x % y + y) % y;
    a1 = a1 + x * m1;
    m1 = m1 * m2 / g;
    return a1;
}
bool check(ll mid,ll k,ll lc){
    ll res=0;
    int maxx=max(n,m)*2;
    for(int i=1;i<=maxx;i++){
        if(!p1[i]||!p2[i]||!dp[i]) continue;
        if(dp[i]<=mid){
            res+=(mid-dp[i])/lc+1;
        }
        if(mid-res<k) return false;
    }
    return mid-res>=k;
}
int main()
{
    ll k;
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        p1[x]=i;
    }
    for(int i=1,x;i<=m;i++){
        scanf("%d",&x);
        p2[x]=i;
    }
    int maxx=max(n,m)*2;
    int gc=gcd(n,m);
    for(int i=1;i<=maxx;i++){
        if(!p1[i]||!p2[i]) continue;
        if(abs(p1[i]-p2[i])%gc!=0) continue;
        dp[i]=excrt(n,m,p1[i],p2[i]);
    }
    ll l=k,r=1e18;
    ll lc=1ll*n*m/gc;
    ll ans;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid,k,lc)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%lld\n",ans);
}

