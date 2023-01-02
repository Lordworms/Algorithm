#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  int ans=3;
  int g;
  for(int i=0;i<n;++i)
  {
    if(i==0)g=arr[i];
    cin>>arr[i];
    g=gcd(g,arr[i]);
  }
  if(g==1)
  {
    cout<<0<<'\n';
    return;
  }
  for(int i=n-1;i>=0;--i)
  {
    if(gcd(g,i+1)==1)
    {
        ans=min(n-i,ans);
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