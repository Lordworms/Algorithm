/*
1. clique: a subgraph that each two vertex has a line
2. figure out different situation
    a. when to make more than two operations?
        when the graph is made of two different cliques
    b. when to make 2 operations?
        let's call a point which did not connect to other cliques a feasible point
        it is a feasible point only if it is not a cut vertex and it is not adjacent to other vertex in other connected component
    c. 
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>>mp(n,vector<int>(n));
    vector<int>deg(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            char c;
            cin>>c;
            mp[i][j]=c-'0';
            if(mp[i][j])
            {
                deg[i]++;
            }
        }
    }
    vector<vector<int>>cliques;
    vector<bool>vis(n,false);
    for(int i=0;i<n;++i)
    {
        if(vis[i])continue;
        vis[i]=true;
        vector<int>cli(1,i);
        for(int j=0;j<cli.size();++j)
        {
            for(int k=0;k<n;++k)
            {
                if(!vis[k]&&mp[cli[j]][k])
                {
                    cli.push_back(k);
                    vis[k]=true;
                }
            }
        }
        cliques.push_back(cli);
    }
    if(cliques.size()==1)
    {
        cout<<0<<"\n";
        return;
    }
    int wp=-1;
    for(auto& cli:cliques)
    {
        int size=cli.size();
        if(size==1)
        {
            wp=cli[0];
            break;
        }
        int fcnt=0;//check if the subset is a clique
        for(auto& v:cli)
        {
            if(deg[v]==size-1)
            {
                ++fcnt;
            }
        }
        if(fcnt==size)//fully connectd a clique
        {
            continue;
        }
        if(fcnt==0)
        {
            wp=cli.back();//get the single point in the subset
            break;
        }
        for(auto& v:cli)
        {
            if(deg[v]<size-1)
            {
                wp=v;
                break;
            }
        }
        break;
    }
    if(wp!=-1)
    {
        cout<<1<<'\n';
        cout<<wp+1<<'\n';
        return;
    }
    else if(cliques.size()>2)
    {
        cout<<2<<'\n';
        cout<<cliques[0][0]+1<<' '<<cliques[1][0]+1<<'\n';
    }
    else 
    {
        auto& v=(cliques[0].size()>cliques[1].size()?cliques[1]:cliques[0]);
        cout<<v.size()<<'\n';
        for(auto& x:v)
        {
            cout<<x+1<<' ';
        }
        cout<<'\n';
    }
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