#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  ll sum=0;
  vector<int>minOp(n,-1);
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
    if(arr[i]%2==0)
    {
        int x=arr[i];
        int op=0;
        while(x%2==0)
        {
            x/=2;
            op++;
        }
        minOp[i]=op;
    }
    if(arr[i]%2)
    {
        int x=arr[i];
        int op=0;
        while(x%2)
        {
            x/=2;
            op++;
        }
        minOp[i]=op;
    }
    sum+=arr[i];
  }
  if(sum%2==0)
  {
    cout<<0<<'\n';
    return;
  }
  int ans=INT_MAX;
  for(int i=0;i<n;++i)
  {
    if(minOp[i]!=-1)
    {
        ans=min(ans,minOp[i]);
    }
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