#include <bits/stdc++.h>
using namespace std;
using ll=long long;
unordered_map<int,int>mp;
void solve()
{
  int n;
  cin>>n;
  ll ans=0;
  if(n<10)
  {
    ans=n;
  }
  else if(n<=100)
  {
    ans=n/10+9;
  }
  else
  {
    int h;
    for(int i=1;i<=6;++i)
    {
        int fac=pow(10,i);
        if(n>fac)
        {
            ans+=10;
        }
        else
        {
            h=n/(fac/10)-1;
            break;
        }
        if(i>1)ans-=1;
    }
    ans+=h;
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