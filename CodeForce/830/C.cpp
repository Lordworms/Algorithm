#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,q;
  cin>>n>>q;
  vector<ll>arr(n+1);
  vector<ll>sum(n+1);
  vector<ll>Xor(n+1);
  vector<int>left(n+2),right(left);
  auto query=[&](int l,int r)
  {
    return sum[r]-sum[l-1]-(Xor[r]^Xor[l-1]);
  };
  for(int i=1;i<=n;++i)
  {
    cin>>arr[i];
    sum[i]=sum[i-1]+arr[i];
    Xor[i]=Xor[i-1]^arr[i];
    if(arr[i])left[i]=i;
    else left[i]=left[i-1];
  }
  for(int i=n;i>=1;--i)
  {
    if(arr[i])right[i]=i;
    else right[i]=right[i+1];
  }
  right[n+1]=n+1;
  ll ans=0;
  ll l,r;
  while(q--)
  {
    cin>>l>>r;
    ll ans=query(l,r);
    if(!ans)
    {
        cout<<l<<" "<<l<<'\n';
        continue;
    }
    ll ansl=l,ansr=r;
    while(l<=r&&query(l,r)==ans)
    {
        ll rlim=r;
        while(l<=rlim)
        {
            if(query(l,rlim)==ans)
            {
                if(rlim-l<ansr-ansl)
                {
                    ansl=l;
                    ansr=rlim;
                }
            }
            else break;
            rlim=left[rlim-1];
        } 
        l=right[l+1];
    }
    cout<<ansl<<' '<<ansr<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}