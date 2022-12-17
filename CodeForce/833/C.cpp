#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2e5+10;
void solve()
{
    int n;
    cin>>n;
    vector<ll>arr(n);
    ll ans=0;
    bool isFirst=true;
    unordered_map<ll,ll>freq;
    ll nowMax=0;
    ll sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        sum+=arr[i];
        if(arr[i]==0)
        {
            if(!isFirst)ans+=nowMax;
            else ans+=freq[0];
            isFirst=false;
            freq.clear();
            nowMax=0;
        }
        freq[sum]++;
        nowMax=max(nowMax,freq[sum]);
    }
    if(!isFirst)ans+=nowMax;
    else ans+=freq[0];
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}