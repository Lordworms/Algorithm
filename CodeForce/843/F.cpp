/*
    https://zhuanlan.zhihu.com/p/598748332
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=900;
using pii=pair<int,int>;
void solve()
{
    int t;
    int n,type,mod;
    cin>>t>>type;
    vector<ll>dp(MAXN);
    dp[0]=1;
    if(type==2)cin>>mod;
    else goto beg;
    for(int times=0;times<4;++times)
    {
        for(int i=1;i<MAXN;++i)
        {
            for(int j=i;j<MAXN;++j)
            {
                dp[j]+=dp[j-i];
                dp[j]%=mod;
            }
        }
    }
    beg:
    while(t--)
    {
        cin>>n;
        vector<pii>premeter;
        ll t=1,a,b;
        while(t*t<n)++t;
        if((t-1)*t>=n)
        {
            a=t-1,b=t;
        }
        else
        {
            a=t,b=t;
        }
        while(a*b>=n)premeter.push_back({a--,b++});
        if(type==1)
        {
            a=premeter[0].first,b=premeter[0].second;
            cout<<a<<' '<<b<<'\n';
            for(int i=1;i<a;++i)
            {
                for(int j=1;j<=b;++j)
                {
                    cout<<'#';
                }
                cout<<'\n';
            }
            for(int i=1;i<=a*b-n;++i)cout<<'.';
            for(int i=a*b-n+1;i<=b;++i)cout<<'#';
            cout<<'\n';
        }
        else
        {
            ll ans=0;
            auto [a,b]=premeter[0];
            cout<<(a+b)*2<<' ';
            for(auto pi:premeter)
            {
                auto [a,b]=pi;
                if(a==b)
                {
                    ans+=dp[a*b-n];
                }
                else
                {
                    ans+=2ll*dp[a*b-n];
                }
                ans%=mod;
            }
            cout<<ans<<'\n';
        }
    }
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}