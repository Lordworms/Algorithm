#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=75;
ll fib[N],sum[N];
void init()
{
    fib[1]=fib[2]=1;
    sum[1]=1,sum[2]=2;
    for(int i=3;i<N;++i)
    {
        fib[i]=fib[i-1]+fib[i-2];
        sum[i]=fib[i]+sum[i-1];
    }
}
void solve()
{
  int n;
  cin>>n;
  vector<ll>a(n+1);
  ll s=0;
  multiset<array<ll,2>>st;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    s+=a[i];
    st.insert({a[i],(ll)1e9});
  }
  if(count(sum+1,sum+N,s)==0)
  {
    cout<<"NO\n";
    return;
  }
  int idx=find(sum+1,sum+N,s)-sum;
  for(int i=idx;i>=1;--i)
  {
    auto tmp=--st.end();
    if((*tmp)[0]<fib[i]||(*tmp)[1]==i+1)
    {
        cout<<"NO"<<'\n';
        return;
    }
    ll val=(*tmp)[0];
    st.erase(--st.end());
    if(val>fib[i])st.insert({val-fib[i],i});
  }
  cout<<"YES\n";
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