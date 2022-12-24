#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>b(n);
  for(auto& k:b)cin>>k;
  vector a(n,vector<int>(n,0));
  for(int i=0;i<n;++i)
  {
    a[i][i]=b[i];
    int j=i;
    while(j>0)
    {
      a[i][j-1]=(a[i][j]-i+n)%n;
      --j;
    }
    j=i;
    while(j<n-1)
    {
        a[i][j+1]=(a[i][j]+i+n)%n;
        ++j;
    }
  }
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<n;++j)
    {
        cout<<a[i][j];
        if(j==n-1)cout<<'\n';
        else cout<<' ';
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
  solve();
  return 0;
}