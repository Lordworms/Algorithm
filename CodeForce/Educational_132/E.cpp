/*
    dis(i) means the xor sum between i and 1
    so cost(i,j)=dis(i)^dis(j)^LCA(i,j)

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<ll>a(n),b(n);
  vector<ll>dis(n);
  for(int i=0;i<n;++i)cin>>a[i];
  vector<vector<int>>E(n);
  for(int i=0;i<n-1;++i)
  {
    int x,y;
    cin>>x>>y;
    --x,--y;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  int ans=0;
  set<int>st[n];
  function<void(int,int)>init=[&](int now,int fa)
  {
    b[now]=a[now];
    if(fa!=-1)b[now]^=b[fa];
    for(int v:E[now])
    {
        if(v!=fa)
        {
            init(v,now);
        }
    }
  };
  function<void(int,int)>dfs=[&](int now,int fa)
  {
    st[now].insert(b[now]);
    bool flag=false;
    for(int v:E[now])
    {
        if(v==fa)continue;
        dfs(v,now);
        if(st[now].size()<st[v].size())st[now].swap(st[v]);
        for(int x:st[v])
        {
            flag|=st[now].count(x^a[now]);
        }
        for(int x:st[v])
        {
            st[now].insert(x);
        }
        st[v].clear();
    }
    if(flag)
    {
        ++ans;
        st[now].clear();
    }
  };
  init(0,-1);
  dfs(0,-1);
  cout<<ans<<"\n";
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