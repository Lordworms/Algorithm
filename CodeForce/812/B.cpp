/*
    当且仅当数组呈现山峰状的时候满足要求
    即 a1<=a2<=aid>=aid+1>=....>=an
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  int id=max_element(a.begin(),a.end())-a.begin();
  for(int i=0;i<id;++i)
  {
    if(a[i]>a[i+1])
    {
        cout<<"NO"<<'\n';
        return;
    }
  }
  for(int i=n-1;i>id;--i)
  {
    if(a[i-1]<a[i])
    {
        cout<<"NO"<<'\n';
        return;
    }
  }
  cout<<"YES"<<'\n';
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