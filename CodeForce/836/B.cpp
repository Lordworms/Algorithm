#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    if(n%2)
    {
        for(int i=0;i<n;++i)
        {
            cout<<2<<' ';
        }
        cout<<'\n';
        return;
    }
    else
    {
        for(int i=0;i<n-2;++i)
        {
            cout<<2<<' ';
        }
        cout<<1<<' '<<3<<'\n';
    }
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