#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
int gcd(int x,int y){return (y==0?x:gcd(y,x%y));}
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n+1);
  int cnt=0,g;
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
    if(i==0)g=a[i];
    else g=gcd(g,a[i]);
    if(a[i]==1)
    {
        ++cnt;
    }
  }
  if(g!=1)
  {
    cout<<-1<<'\n';
    return;
  }
  if(cnt)
  {
    cout<<n-cnt<<'\n';
    return;
  }
  int ans=INT_MAX;
  for(int i=0;i<n;++i)
  {
    int x=a[i];cnt=0;
    for(int j=i+1;j<n;++j)
    {
        x=gcd(x,a[j]);
        ++cnt;
        if(x==1)
        {
            ans=min(ans,cnt+n-1);
            break;
        }
    }
  }
  cout<<(ans==INT_MAX?-1:ans)<<'\n';
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