#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct LB
{
   vector<ll>p;
   int base;
   LB(int base=64)
   {
        p.resize(base);
        this->base=base;
   }   
   inline bool insert(ll x)
   {
        for(int i=base-1;i>=0;--i)
        {
            if(!(x>>i))continue;
            if(!p[i])
            {
                p[i]=x;
                break;
            }
            x^=p[i];
        }
        return x==0;
   }
   inline ll query(int x=0)
   {
        unsigned long long ans=0;
        for(int i=base-1;i>=0;--i)
        {
            ans=max(ans,ans^p[i]);
        }
        return ans;
   }
   void merge(const LB& aa)
   {
        for(int i=base-1;i>=0;--i)
        {
            if(aa.p[i])
            {
                insert(aa.p[i]);
            }
        }
   }
};
ll quick_pow(ll x,ll exp,int p)
{
      ll ans=1;
      while(exp)
      {
        if(exp&1)ans=ans*x%p;
        exp>>=1;
        x=x*x%p;
      }
      return ans;
}
vector<int>prime={2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47, 53,59,61,67};
void solve()
{
  LB lb(20);
  int n;cin>>n;
  for(int i=1;i<=n;++i)
  {
    int x;cin>>x;
    int now=0;
    for(int j=0;j<prime.size();++j)
    {
        now<<=1;
        while(!(x%prime[j]))
        {
            x/=prime[j];
            now^=1;
        }
    }
    lb.insert(now);
  }
  for(int i=lb.base-1;i>=0;--i)
  {
    n-=(lb.p[i]!=0);
  }
  cout<<quick_pow(2,n,MOD)-1<<'\n';
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