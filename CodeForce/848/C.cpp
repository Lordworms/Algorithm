#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=5e5;
ll all[N];
void init()
{
    for(int i=1;i<N;++i)
    {
        all[i]=1ll*i*(i+1)/2;
    }
}
void solve()
{
  int n,k;
  string a,b;
  cin>>n>>k;
  cin>>a>>b;
  vector<int>used;
  vector<int>exist(26,false),st(26,false);
  int cnt=0;
  ll ans=0;
  function<void(int)>dfs=[&](int x)
  {
    if(cnt>=min(k,(int)used.size()))
    {
        ll tmp=0;
        for(int i=0;i<n;++i)
        {
            int j=i;
            if(!st[a[j]-'a']&&a[j]!=b[j])continue;
            while(j<n&&(a[j]==b[j]||st[a[j]-'a']))++j;
            ll len=j-i;
            i=j;
            tmp+=all[len];
        }
        ans=max(ans,tmp);
        return;
    }
    for(int i=x+1;i<used.size();++i)
    {
        if(!st[used[i]-'a'])
        {
            st[used[i]-'a']=1;
            ++cnt;
            dfs(i);
            --cnt;
            st[used[i]-'a']=0;
        }
    }
  };
  for(int i=0;i<n;++i)
  {
    if(!exist[a[i]-'a']&&a[i]!=b[i])
    {
        exist[a[i]-'a']=true;
        used.push_back(a[i]);
    }
  }
  dfs(-1);
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
  init();
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}