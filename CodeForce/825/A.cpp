#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n),b(n);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
  }
  for(int i=0;i<n;++i)
  {
    cin>>b[i];
  }
  int dif=0;
  for(int i=0;i<n;++i)
  {
    if(a[i]!=b[i])
    {
        dif++;
    }
  }
  ll asum=accumulate(a.begin(),a.end(),0ll),bsum=accumulate(b.begin(),b.end(),0ll);
  ll ddif=abs(asum-bsum);
  if(asum==bsum&&dif==ddif)
  {
    cout<<0<<'\n';
    return;
  }
  cout<<ddif+(dif>ddif?1:0)<<'\n';
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