/*
    it is a symmytry problem which means that if you cannot reach left, you cannot reach right
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>arr(n+1);
  for(int i=1;i<=n;++i)cin>>arr[i];
  ll now=0,maxRev=0,nowRev=0;
  for(int i=k,j=k;i<=n;++i)
  {
    now+=arr[i];
    if(now+maxRev<0)
    {
        cout<<"NO"<<'\n';
        return;
    }
    while(now+nowRev+arr[j-1]>=0)
    {
        --j;
        nowRev+=arr[j];
        maxRev=max(maxRev,nowRev);
        if(j==0)
        {
            cout<<"YES"<<'\n';
            return;
        }
    }
  }
  cout<<"YES"<<'\n';
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