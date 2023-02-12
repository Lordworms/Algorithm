#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct point{ll x,y,z;};
void solve()
{
  int n;
  cin>>n;
  vector<point>a(n);
  for(int i=0;i<n;++i)
  {
    cin>>a[i].x>>a[i].y>>a[i].z;
  }
  auto calc=[&](point& a,point& b)
  {
    ll l1=abs(a.x-b.x);
    ll l2=abs(a.y-b.y);
    ll l3=abs(a.z-b.z);
    return l1*l1+l2*l2+l3*l3;
  };
  vector<bool>used(n,false);
  for(int i=0;i<n;++i)
  {
    if(used[i])continue;
    int id=-1;
    ll dis=1e18;
    for(int j=i+1;j<n;++j)
    {
        if(used[j])
        {
            continue;
        }
        ll d=calc(a[i],a[j]);
        if(d<dis)
        {
            id=j;
            dis=d;
        }
    }
    cout<<i+1<<' '<<id+1<<'\n';
    used[i]=used[id]=true;
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}