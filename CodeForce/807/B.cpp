#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n+1);
  ll ans=0;
  int zero_flag=false;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    if(i==n)break;
    if(a[i])
    {
        zero_flag=true;
    }
    if(zero_flag&&a[i]==0)
    {
        ans+=1;
    }
    ans+=a[i];
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