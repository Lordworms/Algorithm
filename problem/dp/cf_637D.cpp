#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<ll,ll>;
void solve()
{
  int n,m,s,d;
  cin>>n>>m>>s>>d;
  vector<ll>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a.begin()+1,a.end());
  vector<pii>segs;
  segs.push_back(make_pair(0ll,0ll));
  int i=1;
  while(i<=n)
  {
    pii seg;
    seg.first=a[i];
    while(i+1<=n&&a[i+1]-a[i]-1<=s)
    {
        ++i;
    }
    seg.second=a[i];
    segs.push_back(seg);
    ++i;
  }
  n=segs.size()-1;
  auto check=[&]()
  {
    segs[0].second=-1;
    for(int i=1;i<=n;++i)
    {
        if(s>=(segs[i].first-segs[i-1].second-1)||segs[i].second-segs[i].first+2>d)
        {
            return false;
        }
    }
    return true;
  };
  function<void(int,int)>print=[&](int i,int des)
  {
    if(!i)
    {
        cout<<"RUN "<<segs[1].first-1<<'\n';
        return;
    }
    print(i-1,segs[i].first-1);
    cout<<"JUMP "<<segs[i].second-segs[i].first+2<<'\n';
    if(segs[i].second+1!=des)
    {
        cout<<"RUN "<<des-segs[i].second-1<<'\n';
    }
  };
  if(!check())
  {
    cout<<"IMPOSSIBLE\n";
    return;
  }
  print(n,m);
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