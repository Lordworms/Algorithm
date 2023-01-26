/*
    lcm(i,j,k)<i+j+k => lcm(i,j,k)<3k-2<3k
    lcm(i,j,k)<3k lcm(i,j,k)%k==0
    lcm=k or 2k
    I.lcm == k
        then the answer is C(m,2) which m==factor number of k
    II.
        lcm == 2*k
        i,j are both factor of 2*k

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=2e5+10;
void solve()
{
  ll l,r;
  cin>>l>>r;
  vector<ll>f(r+1,0);
  for(int i=l;i<r;++i)
  {
    for(int j=i*2;j<=r;j+=i)
    {
        f[j]++;
    }
  }
  ll n=r-l+1;
  ll ans=n*(n-1)*(n-2)/6;
  for(int i=l+2;i<=r;++i)
  {
    ans-=(f[i]*(f[i]-1)/2);
    if(i%3)continue;
    if(i%2==0&&i/2>=l)--ans;
    if(i%5==0&&i/5*2>=l)--ans;
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
  while(T--)
  {
    solve();
  }
  return 0;
}