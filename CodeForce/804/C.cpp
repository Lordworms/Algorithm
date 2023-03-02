#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1),pos(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    pos[a[i]]=i;
  }
  int l=pos[0],r=l;
  ll ans=1;
  for(int i=1;i<n;++i)
  {
    if(pos[i]>r)r=pos[i];
    else if(pos[i]<l)l=pos[i];
    else
    {
        ans=ans*(r-l+1-i)%MOD;
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
  while(T--)
  {
    solve();
  }
  return 0;
}