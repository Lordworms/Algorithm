#include <bits/stdc++.h>
using namespace std;
int n,k;
using ll=long long;
void solve()
{
  cin>>n>>k;
  vector<ll>s(n+1);
  for(int i=n-k+1;i<=n;++i)cin>>s[i];
  if(k==1)
  {
    cout<<"Yes"<<endl;
    return;
  }
  for(int i=n-k+1;i<=n-2;++i)
  {
    if(s[i+2]-s[i+1]<s[i+1]-s[i])
    {
      cout<<"No"<<endl;
      return;
    }
  }
  ll t=s[n-k+2]-s[n-k+1];
  if(t*(n-k+1)>=s[n-k+1])
  {
    cout<<"Yes"<<endl;
    return;
  }
  else cout<<"No"<<endl;
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