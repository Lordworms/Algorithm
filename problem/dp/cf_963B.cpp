/*
    若根节点消除了，但是叶子结点没有消除那就寄了，所以优先消除dfs序大的节点（叶节点）

*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1),deg(n+1);
    vector<vector<int>>E(n+1);
    for(int i=1;i<=n;++i){
       int v;
       cin>>v;
       if(v){
        E[i].push_back(v);
        E[v].push_back(i);
        ++deg[i];
        ++deg[v];
       }
    }
    vector<int>fa(n+1);
    vector<int>st;
    function<void(int,int)>dfs1=[&](int x,int f){
        st.push_back(x);
        fa[x]=f;
        for(int v:E[x]){
            if(v==f)continue;
            dfs1(v,x);
        }
    };
    vector<int>ans;
    vector<int>vis(n+1);
    function<void(int)>dfs2=[&](int x){
        ans.push_back(x);
        vis[x]=1;
        for(int v:E[x]){
            deg[v]--;
            if(v==fa[x]||vis[v])continue;
            if(deg[v]%2==0)dfs2(v);
        }
    };
    dfs1(1,0);
    while(!st.empty()){
        auto cur=st.back();
        st.pop_back();
        if(deg[cur]%2==0){
            dfs2(cur);
        }
    }
    if(ans.size()==n){
        cout<<"YES\n";
        for(int i=0;i<n;++i){
            cout<<ans[i]<<"\n";
        }
    }else{
        cout<<"NO\n";
    }
    return 0;
}