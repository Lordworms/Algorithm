#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;
  cin>>n>>k;
  if(k%2==0&&(k%4)==0)
  {
    cout<<"NO"<<'\n';
    return;
  }
  cout<<"YES"<<'\n';
  if(k%2)
  {
    for(int i=1;i<=n/2;++i)
    {
        int l=n-i+1;
        if(i%4==0)
        {
            cout<<l<<' '<<i<<'\n';
        }
        else if(l%4==0)
        {
            cout<<i<<' '<<l<<'\n';
        }
        else if(i%2)
        {
            cout<<i<<' '<<l<<'\n';
        }
        else 
        {
            cout<<l<<' '<<i<<'\n';
        }
    }
    return;
  }
  else
  {
    for(int i=1;i<=n/2;++i)
    {
       int l=n-i+1;
       if(i%4==0)
       {
            cout<<l<<' '<<i<<'\n';
       }
       else if(l%4==0)
       {
            cout<<i<<' '<<l<<'\n';
       }
       else if(i%2)
       {
            cout<<l<<' '<<i<<'\n';
       }
       else 
       {
            cout<<i<<' '<<l<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}