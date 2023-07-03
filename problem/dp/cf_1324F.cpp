#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]=(a[i]==0?-1:1);
    }
    vector<vector<int>>E(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    function<void(int,int)>dfs1=[&](int x,int f){
        for(int v:E[x]){
            if(v==f)continue;
            dfs1(v,x);
            if(a[v]>0)a[x]+=a[v];
        }
    };
    function<void(int,int)>dfs2=[&](int x,int f){
        for(int v:E[x]){
            if(v==f)continue;
            if(a[v]>0){
                a[v]=max(a[x],a[v]);
            }else{
                a[v]=max(a[v],a[x]+a[v]);
            }
            dfs2(v,x);
        }
    };
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i){
        cout<<a[i]<<" \n"[i==n];
    }
    return 0;
}