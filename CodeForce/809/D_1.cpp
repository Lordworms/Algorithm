#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  int ans=INT_MAX;
  for(int now=a[n-1]/k;now<=a[n-1];++now)
  {
    int minx=now;
    bool flag=true;
    for(int i=0;i<n;++i)
    {
        if(a[i]/k>now)
        {
            flag=false;
            break;
        }
        int l=1,r=k,m;
        while(l<r)
        {   
            m=(l+r)>>1;
           if(a[i]/m<=now)
           {
                r=m;
           }
           else
           {
                l=m+1;
           }
        }
        minx=min(a[i]/r,minx);
    }
    if(flag)ans=min(ans,now-minx);
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