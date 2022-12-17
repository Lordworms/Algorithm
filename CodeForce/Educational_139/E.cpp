#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=3e5+10;
vector<int>arr;
map<vector<int>,ll>mp[MAXN];
int n;
using pii=pair<vector<int>,int>;
pii getAns(int x,vector<int>a)
{
    if(x==0)
    {
        return {a,1};
    }
    bool flag=false;
    for(int i=0;i<a.size()&&!flag;++i)
    {
        if((a[i]&x)>0)
        {
            flag=true;
            a[i]=x;
        }
    }
    if(!flag)
    {
        a.push_back(x);
        return {a,1};
    }
    return {a,0};
}
ll calc(int i,vector<int>a)
{
    if(i==n)
    {
        return 0ll;
    }
    if(mp[i].count(a))
    {
        return mp[i][a];
    }
    auto ins=getAns(arr[i],a);
    return (mp[i][a]=ins.second*1ll*(n-i)+calc(i+1,ins.first));
}
void solve()
{
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=calc(i,vector<int>(0));
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
  solve();
  return 0;
}