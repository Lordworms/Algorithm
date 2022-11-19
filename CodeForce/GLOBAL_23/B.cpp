/*
  we would like to know how many 1 are on the right part
  ans=min(ans,max(k0,k1))
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  int k0=0,k1=0;
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
    if(arr[i]==0)++k0;
  }
  int ans=max(k0,k1);
  for(int i=0;i<n;++i)
  {
    if(arr[i]==1)
    {
      k1++;
    }
    else k0--;
    ans=min(ans,max(k0,k1));
  }
  cout<<ans<<"\n";

}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}