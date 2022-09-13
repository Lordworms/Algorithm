/*
https://codeforces.com/contest/1728/problem/F
可以转化为一个二分图匹配的问题
注意用map存键值对，可以从小到大遍历key的值
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1010;
int n,b;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  map<int,int>mp;
  vector<vector<int>>E;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=0;i<n;++i)
  {
    for(int p=1;p<=n;++p)
    {
      b=p*a[i];
      if(!mp.count(b))
      {
        mp[b]=mp.size();
        E.push_back({});
      }
      E[mp[b]].push_back(i);
    }
  }
  vector<int>vis(mp.size(),-1),yx(n,-1);
  function<bool(int,int)>find=[&](int x,int s)
  {
    vis[x]=s;
    for(auto y:E[x])
    {
        if(yx[y]==-1||vis[yx[y]]!=s&&find(yx[y],s))//连的不是同一个点(vis[yx[y]]!=s)
        {
          yx[y]=x;
          return true;
        }
    }
    return false;
  };
  ll ans=0;
  int cnt=0;
  for(auto [i,id]:mp)
  {
    if(cnt<n&&find(id,cnt+1))//优化一下，我们每一次找的都是下一个编号代表的值
    {
      cnt++;
      ans+=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}