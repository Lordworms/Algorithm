/*
    use a map to store the frequencey of platitute and then traverse the map, with each traverse, compute the answer.
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    map<int,int>mp;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        mp[x]++;
    }
    ll ans=-1;
    ll s=0;
    for(auto [_,cnt]:mp)
    {
        s+=cnt;
        ans=max(ans,s*(n-s));
    }   
    if(mp.size()==1)ans=n/2;
    cout<<ans<<'\n';
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}