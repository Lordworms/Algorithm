#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    vector<int>a(6);
    for(int i=0;i<6;++i)
    {
        cin>>a[i];
    }
    if(a[0]!=a[2]&&a[0]!=a[4]&&a[2]!=a[4])
    {
        cout<<"YES"<<'\n';
    }
    else if(a[1]!=a[3]&&a[1]!=a[5]&&a[3]!=a[5])
    {
        cout<<"YES"<<'\n';
    }
    else
    {
        cout<<"NO"<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}