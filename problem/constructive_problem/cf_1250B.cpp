#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
void solve()
{
  int n,k;cin>>n>>k;
  vector<pii>cnt(k);
  for(int i=0;i<k;++i)cnt[i].first=i;
  for(int i=0;i<n;++i)
  {
    int t;cin>>t;--t;
    cnt[t].second++;
  }
  sort(cnt.begin(),cnt.end(),[&](pii a,pii b)
  {
    return a.second>b.second;
  });
  if(k==1)
  {
    cout<<n<<'\n';
    return;
  }
  auto check=[&](int siz)
  {
    int l=0,r=k-1,res=0;
    while(l<=r)
    {
        if(cnt[l].second+cnt[r].second<=siz)
        {   
            l++,r--;
        }
        else
        {
            l++;
        }
        ++res;
    }
    return res;
  };
  //let's iterate over cnt[0] to cnt[0]+cnt[1] 
  int ans=1e16;
  int mx=-1e16;
  for(int i=0;i<k;++i)
  {
    mx=max(mx,cnt[i].second+cnt[k-i-1].second);
  }
  for(int siz=cnt[0].second;siz<=mx;++siz)
  {
    int num=check(siz);
    int v=num*siz;
    ans=min(v,ans);
    if(num==k/2.0)
    {
        break;
    }
  }
  cout<<ans<<'\n';
  return;
}
signed main()
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