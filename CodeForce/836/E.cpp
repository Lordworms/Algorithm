/*
    1. you should know that when the dicrepency would happen, when there are a row or colum that is all empty, in that case, the combination would happen.
    2. so we need to know how many discrepency in colum and row
    3. the combine answer is actually h^(combine_time)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll quick_pow(ll x,ll exp,int p)
{
      ll ans=1;
      while(exp)
      {
        if(exp&1)ans=ans*x%p;
        exp>>=1;
        x=x*x%p;
      }
      return ans;
}
void solve()
{
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<int>>G(n,vector<int>(m,-1));
    vector<array<int,2>>E[n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>G[i][j];
        }
    }
    int valid=1;
    vector<int>connected(n,-1);
    function<void(int,int)>dfs=[&](int now,int value)
    {
        connected[now]=value;
        for(auto nxt:E[now])
        {
            if(connected[nxt[0]]==-1)
            {
                dfs(nxt[0],(value+nxt[1])%h);
            }
            else if((value+nxt[1])%h!=connected[nxt[0]])
            {
                valid=0;
            }
        }
    };

    int op1=0,op2=0;
    for(int j=0;j<m;++j)
    {
        int st=-1;
        int all_empty=1;
        for(int i=0;i<n;++i)
        {
            if(G[i][j]!=-1)
            {
               if(st!=-1)
               {
                 E[i].push_back({st,(G[i][j]-G[st][j]+h)%h});
                 E[st].push_back({i,(G[st][j]-G[i][j]+h)%h});
               }
               st=i; 
               all_empty=0;
            }
        }
        op2+=all_empty;
    }
    for(int i=0;i<n;++i)
    {
        if(connected[i]==-1)
        {
            op1++;
            dfs(i,0);
        }
    }
    cout<<quick_pow(h,op1+op2-1,MOD)*valid<<'\n';
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