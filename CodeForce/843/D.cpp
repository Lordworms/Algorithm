/*
    给每个数的质因数找一个中转点，然后我们建图的时候就只需要nlogn条边惹
    之后跑个最短路即可，注意跑最短路的时候要从终点开始向前递推
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=3e5+10;
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1);
  vector<ll>dis(MAXN+n,1e18);
  vector<vector<int>>E(MAXN+n);
  vector<bool>vis(MAXN+n);
  vector<int>trace(MAXN+n);
  vector<int>ans;
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i)
  {
    int x=a[i];
    for(int j=2;j*j<=x;++j)
    {
        if(x%j==0)
        {
            while(x%j==0)
            {
                x/=j;
            }
            E[i].push_back(n+j);
            E[n+j].push_back(i);
        }   
    }
    if(x>1)
    {
        E[i].push_back(n+x);
        E[n+x].push_back(i);
    }
  }
  queue<int>q;

  int s,t;cin>>s>>t;
  q.push(s);
  dis[s]=0;
  while(!q.empty())
  {
    auto h=q.front();
    q.pop();
    if(vis[h])continue;
    for(int v:E[h])
    {
        if(dis[v]>dis[h]+1)
        {
            dis[v]=dis[h]+1;
            q.push(v);
            //vis[v]=true;
            trace[v]=h;
        }
    }
  } 
  if(dis[t]==1e18)
  {
    cout<<-1<<'\n';
  }
  else
  {
    while(1)
    {
        if(t<=n)ans.push_back(t);
        if(t==s)break;
        t=trace[t];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" \n"[i==ans.size()-1];
    }
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}