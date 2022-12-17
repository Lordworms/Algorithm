#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  unordered_map<int,int>mp;
  unordered_map<int,int>sol;
  vector<int>arr(n);
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
    mp[arr[i]]++;
  } 
  sort(arr.begin(),arr.end());
  auto lim=*(arr.begin())-arr.back();
  ll ans=0;
  for(int i=0;i<n;++i)
  {
    auto plus=0;
    plus+=mp[lim+arr[i]];
    plus+=mp[arr[i]-lim];
    if(arr[i]==lim+arr[i])--plus;
    if(arr[i]==arr[i]-lim)--plus;
    if(arr[i]-lim==lim+arr[i])plus/=2;
    ans+=plus;
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