#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
bool flag=false;
void solve()
{
  int ans=0,n;
  cin>>n;
  vector<int>a(n);
  vector<int>mp(n+1);
  iota(mp.begin(),mp.end(),0);
  vector<int>less(n+1,n),st;
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
  }
  int pos=-1;
  for(int i=n-1;i>=1;--i)
  {
    if(a[i]<a[i-1])
    {
        pos=i-1;
        break;
    }
  }
  unordered_set<int>ss;
  for(int i=0;i<=pos;++i)
  {
    if(!ss.count(a[i]))
    {
        ss.insert(a[i]);
        mp[a[i]]=0;
        ++ans;
    }
  }
  for(int i=n-1;i>pos+1;--i)
  {
    if(mp[a[i]]<mp[a[i-1]])
    {
        mp[a[i-1]]=0;
        ++ans;
    }
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
  int T;
  cin>>T;
  int cnt=0;
  while(T--)
  {
    solve();
  }
  return 0;
}