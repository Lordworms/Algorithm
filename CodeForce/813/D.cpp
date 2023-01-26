/*
  the length must be min(d(i,i+1),2*m) (m is the shortest length of the graph)
  as we know this, so the goal is to make d(i,i+1) or 2*m great
  if the answer is d(i,i+1) then we just need to make a[i] equals to ANS
  if the answer is 2*m ,then we need to maximize it, so we could just make 
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
const int ANS=1e9;
void solve()
{
  int n,k;cin>>n>>k;
  vector<pii>v(n);
  vector<int>a(n);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
    v[i]={a[i],i};
  }
  sort(v.begin(),v.end());// first sort, get the lowest k-1 elements
  for(int i=0;i<k-1;++i)
  {
    v[i].first=a[v[i].second]=ANS;
  }
  sort(v.begin(),v.end());//second sort
  int ans1=min(2*v[0].first,v[n-1].first);//first calculate (whether the i in in the minimum k elements)
  v[0].first=ANS,a[v[0].second]=ANS;
  sort(v.begin(),v.end());
  int ans2=-1;
  for(int i=1;i<n;++i)
  {
    ans2=max(ans2,min(a[i],a[i-1]));
  }
  ans2=min(ans2,2*v[0].first);
  cout<<max(ans1,ans2)<<'\n';
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