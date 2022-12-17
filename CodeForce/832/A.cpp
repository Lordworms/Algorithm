#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    ll pos=0,neg=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x>=0)pos+=x;
        else neg+=x;
    }
    cout<<abs(abs(pos)-abs(neg))<<'\n';
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