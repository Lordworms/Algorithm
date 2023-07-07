/**
 * 两遍dfs过，第一遍以1为根计算每个点的父节点和子树的全职和
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;
    vector<ll>a(n+1),dp(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<vector<int>>E(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vector<ll>s(n+1);
    function<void(int,int)>dfs1=[&](int x,int f){
        s[x]=a[x];
        dp[x]=0;
        for(int v:E[x]){
            if(v==f)continue;
            dfs1(v,x);
            s[x]+=s[v];
            dp[x]+=dp[v]+s[v];
        }
    };
    function<void(int,int,ll)>dfs2=[&](int x,int f,ll extra){
        for(int v:E[x]){
            if(v==f)continue;
            dp[v]=(extra+s[x]-s[v])+dp[x]-s[v];//the subtree node of v would be subtraceted s[v] and other nodes would be adding s[x]-s[v];
            dfs2(v,x,extra+s[x]-s[v]);
        }
    };
    dfs1(1,0);
    dfs2(1,0,0);
    ll ans=-1;
    for(int i=1;i<=n;++i){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<'\n';
}