#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
#define x0 x0___
#define y0 y0___
#define pb push_back
#define SZ(X) ((int)X.size())
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define ALL(X) X.begin(),X.end()
#define RALL(X) X.rbegin(),X.rend()
#define rep(i,j,k) for(int i = j;i <= k;i ++)
#define per(i,j,k) for(int i = j;i >= k;i --)
#define mem(a,p) memset(a,p,sizeof(a))
 
 
const ll MOD = 1E9 + 7;
ll qmod(ll a,ll b,ll c) {ll res=1;a%=c; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%c;a=a*a%c;}return res;}
 
template<typename T, typename S>
void upmax(T& a,S b){if(a<b) a=b;}
template<typename T, typename S>
void upmin(T& a,S b){if(a>b) a=b;}
template<typename T>
void W(T b){cout << b << endl;}
void gettle() {while(1);}
void getre() {int t=0;t/=t;}
 
 
/
/
/
/
 
ll x[25];
ll f[25];
ll inv[25];
 
 
 
ll comb(ll n, ll k) // 注意组合数C(n,k) = C(n % p, k % p) * C(n / p, k / p);
{
    n %= MOD;
    if(n < k) return 0LL;
    if(n == k || k == 0) return 1LL;
    if(k > n - k) k = n - k;
    ll t = k;
    ll res = 1;
    while(t) {
        res = res * n % MOD;
        n --;
        t --;
    }
    res = res * inv[k] % MOD;
    return res;
}
ll Lucas(ll n, ll m, ll p)
{
        return m ? Lucas(n/p, m/p, p) * comb(n%p, m%p) % p : 1;
}
 
 
int main()
{
    ll n, s;
    f[0] = 1;
    rep(i,1,20) f[i] = f[i-1] * i % MOD;
    inv[20] = qmod(f[20], MOD-2, MOD);
    per(i,19,0) inv[i] = (inv[i+1] * (i + 1)) % MOD;
    scanf("%lld %lld", &n, &s);
    rep(i,0,n-1) scanf("%lld",&x[i]);
    ll res = 0;
    rep (i,0,(1<<n)-1) {
        ll sum = s;
        ll o = 1;
        rep (j,0,n-1) {
            if((i>>j)&1) {
                sum = sum - x[j] - 1;
                o *= -1;
                if(sum < 0) break;
            }
        }
        if(sum < 0) continue;
        res = (res + o * comb(n + sum - 1, n - 1)) % MOD;
    }
    res = (res % MOD + MOD) % MOD; //
    printf("%lld\n", res);
    return 0;
}
 