#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  int ans=INT_MAX;
  for(int i=0;i<n;++i)
  {
    if(i>0&&i<n-1)
    {
        ans=min(ans,arr[i]-arr[i-1]+arr[i+1]-arr[i]);
    }
    if(i>1)
    {
        ans=min(ans,2*arr[i]-arr[i-1]-arr[i-2]);
    }
    if(i<n-2)
    {
        ans=min(ans,arr[i+1]+arr[i+2]-2*arr[i]);
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