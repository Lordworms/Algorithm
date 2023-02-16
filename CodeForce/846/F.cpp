/*
    https://zhuanlan.zhihu.com/p/601226143
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=3e5+5;
int mu[MAXN],prim[MAXN];
bool flag[MAXN];
vector<vector<int>>fac;
void init(int n)
{
    int cnt=0;
    mu[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!flag[i])prim[cnt++]=i,mu[i]=-1;
        for(int j=0;i*prim[j]<=n;++j)
        {
            flag[i*prim[j]]=true;
            if(i%prim[j]==0)
            {
                mu[i*prim[j]]=0;
                break;
            }
            mu[i*prim[j]]=-mu[i];
        }
    }
    fac.resize(n);
    for(int i=1;i<n;++i)
    {
        for(int j=i;j<n;j+=i)
        {
            fac[j].push_back(i);
        }
    }
}
void solve()
{
  init(MAXN-1);
  int n;cin>>n;
  vector<int>pre(MAXN),suf(pre);
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a.begin()+1,a.end());
  for(int i=1;i<=n;++i)
  {
    for(auto d:fac[a[i]])
    {
        ++suf[d];
    }
  }
  ll ans=0;
  ll res=0;
  for(int i=1;i<=n;++i)
  {
    if(i>1)
    {
        for(auto d:fac[a[i-1]])
        {
            res+=mu[d]*suf[d];//?
            pre[d]++;
        }
    }
    for(auto d:fac[a[i]])
    {
        res-=mu[d]*pre[d];//?
        suf[d]--;
    }
    ans+=res;
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}