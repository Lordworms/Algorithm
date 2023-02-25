#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1000+10;
const ll LIM=1ll<<30;
int gcdd[N][N];
vector<int>fac[N];
void init()
{
    for(int i=2;i<N;++i)
    {
        for(int j=i;j<N;j+=j)
        {
            fac[j].push_back(i);
        }
    }
}
ll _gcd(ll a,ll b)
{
    if(gcdd[a][b])return gcdd[a][b];
    return gcdd[a][b]=(b?_gcd(b,a%b):a);
}
void solve()
{
  int n,k;cin>>n>>k;
  vector<ll>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  vector<int>sub_gcd(n+1),f(n+1);
  vector<vector<int>>E(n+1);
  vector<vector<ll>>dp(N,vector<ll>(N,0));
  for(int i=0;i<n-1;++i)
  {
        int x,y;
        cin>>x>>y;
        E[x].push_back(y);
        E[y].push_back(x);
  }
  function<void(int,int)>dfs=[&](int now,int fa)
  {
    sub_gcd[now]=a[now];
    f[now]=fa;
    for(int v:E[now])
    {
        if(fa==v)continue;
        dfs(v,now);
        sub_gcd[now]=_gcd(sub_gcd[v],sub_gcd[now]);
    }
  };
  for(int i=0;i<=n;++i)
  {
    for(int d:fac[a[1]])
    {
        dp[i][d]=-1;
    }
  }
  dfs(1,0);
  auto lcm=[&](ll a,ll b)
  {
    return a/_gcd(a,b)*b;
  };
  function<ll(ll,ll,ll)>cal=[&](ll u,ll d,ll fa)
  { 
    if(sub_gcd[u]%d==0)return 0ll;
    if((a[u]*a[u])%d)return LIM;
    if(dp[u][d]!=-1)return dp[u][d];
    ll res=LIM;
    ll req=d/_gcd(d,sub_gcd[u]);
    for(int v:fac[a[u]])
    {
        if((a[u]*v)%d==0&&d%v==0)
        {
            ll r=1;
            for(int c:E[u])
            {
                if(c==fa)continue;
                r+=cal(c,lcm(d/v,v),u);
            }
            res=min(res,r);
        }
    }
    return dp[u][d]=min(res,LIM);
  };
  ll ans=a[1];
  for(int d:fac[a[1]])
  {
    ll req=0;
    bool flag=false;
    for(int v:E[1])
    {
        ll x=cal(v,d,1);
        if(x>n)
        {
            flag=true;
        }
        req+=x;
    }
    ++req;
    if(flag)continue;
    if(req<=k)
    {
        ans=max(ans,a[1]*d);
    }
  }
  cout<<ans<<'\n';
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  init();
  while(T--)
  {
    solve();
  }
  return 0;
}