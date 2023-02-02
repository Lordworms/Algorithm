#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  string s,t; 
  cin>>s>>t;
  if(s[0]!=t[0]||s.size()!=t.size()||s[s.size()-1]!=t[t.size()-1])
  {
    cout<<-1<<'\n';
    return;
  }
  int cnt_s=0,cnt_t=0;
  vector<int>a(n+1),b(a);
  for(int i=1;i<=n-1;++i)
  {
    a[i]=s[i]!=s[i-1];
    b[i]=t[i]!=t[i-1];
    cnt_s+=a[i];
    cnt_t+=b[i];
  }
  if(cnt_s!=cnt_t)
  {
    cout<<-1<<'\n';
    return;
  }
  int now=1;
  ll ans=0;
  for(int i=1;i<=n-1;++i)
  {
    if(a[i])
    {
        while(now<=n-2&&b[now]==0)++now;
        ans+=abs(i-now);
        ++now;
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