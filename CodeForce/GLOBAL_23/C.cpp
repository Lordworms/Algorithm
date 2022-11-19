#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  const int MAXN=1e5+10;
  vector<int>arr(n);
  map<int,vector<int>>mp;
  for(int i=0;i<n;++i)cin>>arr[i];
  int lim=0;
  for(int i=0;i<n-1;++i)
  {
    if(arr[i]>arr[i+1])
    {
      int dis=arr[i]-arr[i+1]+1;
      mp[dis].push_back(i+2);
    }
  }
  vector<int>ans;
  int order=1;
  for(auto pa:mp)
  {
    int dis=pa.first;
    for(auto i:pa.second)
    {
      while(dis>order)
      {
        ans.push_back(1);
        ++order;
      }
      ans.push_back(i);
      ++order;
    }
  }
  while(order<=n)
  {
    ans.push_back(1);
    ++order;
  }
  for(int i=0;i<n;++i)cout<<ans[i]<<" ";
  cout<<"\n";
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