#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e5+10;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>maxx(N),a(n);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
    int lim=MOD;
    for(int l=1,r;l<=min(k,a[i]);l=r+1)//divide into blocks and make the time complexity O(sqrt(n))
    {
        int t=a[i]/l;
        r=a[i]/t;
        maxx[t+1]=max(lim,maxx[t+1]);
        lim=t;
    }
    maxx[0]=max(maxx[0],lim);
  }
  int now_max=0,ans=INT_MAX;
  for(int i=0;i<=a[0];++i) 
  {
    now_max=max(maxx[i],now_max);
    ans=min(ans,now_max-i);
  }
  cout<<ans<<'\n';
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