#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,k,r,c;
  cin>>n>>k>>r>>c;
  --r,--c;
  int fac=n/k;
  int pos=c;
  vector<vector<char>>ans(n,vector<char>(n));
  int cnt=0;
  for(int i=r;cnt<n;++i)
  {
    ++cnt;
    for(int j=0;j<n;++j)
    {
        if((j-pos)%k==0)
        {
            ans[i%n][j]='X';
        }
        else
        {
            ans[i%n][j]='.';
        }
    }
    if(cnt>=n)break;
    pos=(pos+1)%k;
  }
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<n;++j)
    {
        cout<<ans[i][j];
    }
    cout<<'\n';
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