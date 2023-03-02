#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  if(n%2==0)
  {
    cout<<"NO"<<'\n';
    return;
  }
  cout<<"YES\n";
  ll s=n*(1+2*n);
  int a=1,b=(2*n+1)-n/2-1;
  for(int i=1;i<=(n+1)/2;++i)
  {
    cout<<a<<' '<<b<<'\n';
    a+=2;
    b--;
  }
  a=2;
  b=(2*n+1)-1;
  for(int i=1;i<=n/2;++i)
  {
    cout<<a<<' '<<b<<'\n';
    a+=2;
    b--;
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