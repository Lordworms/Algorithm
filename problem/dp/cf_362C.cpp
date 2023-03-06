/*
    greater[i][j] means the first j elements which is greater than a[i]

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=5010;
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1);
  int maxi=0;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    maxi=max(a[i],maxi);
  }
  vector gt(n+1,vector<int>(n+1)),lt(gt);
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=n;++j)
    {
        if(a[i]>a[j])
        {
            gt[i][j]++;
        }
        gt[i][j]+=gt[i][j-1];
        if(a[i]<a[j])
        {
            lt[i][j]++;
        }
        lt[i][j]+=lt[i][j-1];
    }
  }
  int ori=0,cnt=0,ans;
  for(int i=1;i<=n;++i)
  {
    ori+=gt[i][n]-gt[i][i];
  }
  ans=ori;
  for(int i=1;i<=n;++i)
  {
    for(int j=i+1;j<=n;++j)
    {
        int tmp=ori;
        tmp+=gt[j][j]-gt[j][i];
        tmp-=gt[i][j]-gt[i][i];
        tmp+=lt[i][j]-lt[i][i];
        tmp-=lt[j][j]-lt[j][i];
        if(tmp<ans)
        {
            ans=tmp;
            cnt=0;
        }
        if(tmp==ans){
            ++cnt;
        }
    }
  }
  cout<<ans<<' '<<cnt<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}