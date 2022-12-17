#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  ll sum=0;
  vector<int>arr(n);
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
  }
  sort(arr.begin()+1,arr.end());
  if(arr[0]<=arr[1])
  {
    cout<<"Bob"<<'\n';
  }
  else
  {
    cout<<"Alice"<<'\n';
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