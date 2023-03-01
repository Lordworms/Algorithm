#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e6+10;
void solve()
{
  int n;cin>>n;
  vector<int>range(N),pre(N);
  for(int i=0;i<n;++i)
  { 
    int a,b;
    cin>>a>>b;
    range[a]=b;
  }
  int ans=0;
  for(int i=0;i<N;++i)
  {
    int p=i-range[i]-1;
    if(p<0)
    {
        pre[i]=0;
    }
    else
    {   
        pre[i]=pre[p];
    }
    if(range[i])pre[i]++;
    ans=max(ans,pre[i]);
  }
  cout<<n-ans<<'\n';
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