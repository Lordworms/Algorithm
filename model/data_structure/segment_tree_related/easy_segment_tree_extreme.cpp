#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct ST
{
    vector<ll>arr;
    ll size=0;
    const int LIM=3e5+10;
    ST(ll size):size(size)
    {
        arr.assign(2*size,LIM);
    }
    ll getMin(ll a,ll b)
    {
        return std::min(a,b);
    }
    void update(int id,ll val)
    {
        arr[id+=size]=val;
        for(id/=2;id;id/=2)
        {
            arr[id]=getMin(arr[id<<1],arr[id<<1|1]);
        }
    }
    ll query(ll l,ll r)
    {
        ll L=LIM,R=LIM;
        for(l+=size,r+=size+1;l<r;l/=2,r/=2)
        {
            if(l&1)
            {
                L=getMin(L,arr[l++]);
            }
            else if(r&1)
            {
                R=getMin(R,arr[--r]);
            }
        }
        return min(L,R);
    }
};
void solve()
{
  ll n,k;
  cin>>n>>k;
  vector<int>arr(n);
  ll ans=0;
  unordered_map<int,int>mp;
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
  }
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