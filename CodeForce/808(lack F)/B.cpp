/*
    数字可以重复！可以重复！可以重复！
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll n,l,r;
  cin>>n>>l>>r;
  vector<int>ans(n+1);
  for(int i=1;i<=n;++i)
  {
    ans[i]=r/i*i;
    if(ans[i]<l)
    {
        cout<<"NO\n";
        return;
    }
  }
  cout<<"YES\n";
  for(int i=1;i<=n;++i)
  {
    cout<<ans[i]<<" \n"[i==n];
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