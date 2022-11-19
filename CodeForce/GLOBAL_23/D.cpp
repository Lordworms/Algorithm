#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>G(n);
    for(int i=0;i<n-1;++i)
    {
        int x;cin>>x;
        --x;
        G[i+1].push_back(x);
        G[x].push_back(i+1);
    }
    ll ans=0;
    vector<ll>S(n);
    vector<ll>C(n);
    vector<ll>V(n);
    for(int i=0;i<n;++i)cin>>S[i];
    C[0]=k;
    function<void(int,int)>dfs=[&](int now,int fa)
    {
        ans+=S[now]*C[now];
        vector<int>cd;
        for(auto son:G[now])
        {
            if(son==fa)continue;
            cd.push_back(son);
        }
        int cnt=cd.size();
        vector<ll>addList;//value of subtree
        for(auto son:cd)
        {
            C[son]+=C[now]/cnt;
            dfs(son,now);
            addList.push_back(V[son]);
        }
        if(cnt)
        {
            int rem=C[now]%cnt;
            sort(addList.rbegin(),addList.rend());
            for(int i=0;i<rem;++i)
            {
                ans+=addList[i];
            }
            V[now]=S[now]+addList[rem];//?
        }
        else
        {
            V[now]=S[now];
        }
    };
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}