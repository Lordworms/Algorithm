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
  ll sum=accumulate(a.begin(),a.end(),0ll);
  int pos=-1;
  bool flag=false;
  for(int i=0;i<n;++i)
  {
    if(i<n-1&&!flag&&a[i]==-1&&a[i+1]==-1)
    {
        pos=i;
        flag=true;
    }
    if(!flag&&a[i]==-1)
    {
        pos=i;
    }
  }
  if(pos!=-1)
  {
    if(pos<n-1&&a[pos]==-1&&a[pos+1]==-1)
    {
        sum+=4;
    }
  }
  else
  {
    sum-=4;
  }
  cout<<sum<<'\n';
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