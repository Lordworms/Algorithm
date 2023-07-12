#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>E(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vector<ll>sz(n+1),dep(n+1);
    function<void(int,int)>dfs=[&](int x,int f){
        sz[x]=1;
        for(int v:E[x]){
            if(v==f)continue;
            dep[v]=dep[x]+1;
            dfs(v,x);
            sz[x]+=sz[v];
        }
    };
    dfs(1,0);
    ll ans=0;
    ll num=0;
    for(int i=1;i<=n;++i){
        ans+=sz[i]*(n-sz[i]);
        if(dep[i]%2==1)++num;
    }
    ans+=(num)*(n-num);
    cout<<ans/2<<'\n';
}