#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,c,q;
  cin>>n>>c>>q;
  string s;
  cin>>s;
  map<ll,ll>st,p;
  ll len=s.size();
  int cnt=1;
  st[cnt]=1;
  for(int i=1;i<=c;++i)
  {
    ll a,b;
    cin>>a>>b;
    p[len+1]=a,p[len+b-a+1]=b;
    st[++cnt]=len+1;
    len+=(b-a+1);
  }
  
  while(q--)
  {
    ll k;cin>>k;
    while(k>s.size())
    {
        ll l=1,r=cnt,m;
        while(l<r)
        {
            m=(l+r+1)>>1;
            if(st[m]<=k)
            {
                l=m;
            }
            else
            {
                r=m-1;
            }
        }
        k=p[st[r]]+k-st[r];
    }
    cout<<s[k-1]<<"\n";
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}