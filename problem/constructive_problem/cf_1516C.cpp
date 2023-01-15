#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  vector<int>dp(2e5+10);
  dp[0]=1;
  int sum=accumulate(a.begin(),a.end(),0);
  for(int i=0;i<n;++i)
  {
    for(int j=sum/2;j>=a[i];--j)
    {
        if(dp[j-a[i]])dp[j]=1;
    }
  }
  if(!dp[sum/2]||sum%2)
  {
    cout<<0<<'\n';
    return;
  }
  while(1)
  {
    for(int i=0;i<n;++i)
    {
        if(a[i]%2)
        {
            cout<<1<<'\n';
            cout<<i+1<<'\n';
            return;
        }
        else
        {
            a[i]/=2;
        }
    }
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}