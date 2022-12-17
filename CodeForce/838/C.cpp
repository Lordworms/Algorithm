#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
void solve()
{
  int n;
  string s;
  cin>>n;
  cin>>s;
  int last=0;
  ll ans=1;
  ll sum=0;
  for(int i=0;i<n;++i)
  {
    if(s[i]!=last)
    {
        ans=1;
    }
    else
    {
        ans=ans*2%MOD;
    }
    last=s[i];
    sum=(sum+ans)%MOD;
  }
  cout<<sum<<'\n';
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