#include<bits/stdc++.h>
using namespace std;
const int INF=1e8;
const int N=20;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(N),b(N);
    vector<int>posa(N),posb(N);
    vector<int>right(N,INF);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        posa[a[i]]=i;
    }
    for(int i=1;i<=m;++i){
        cin>>b[i];
    }
    if(n>1)a[n+1]=a[1];
    vector<vector<int>>E(m+1);
    for(int i=m;i>=1;--i){
        posb[b[i]]=i;
        int r=posb[a[posa[b[i]]+1]];//右边最近的后继节点
        if(r){
            E[r].push_back(i);
        }
    }
    vector<int>vis(N),id(N);
    int cur=0;
    function<void(int)>dfs=[&](int x){
        vis[x]=1;
        id[++cur]=x;
        if(cur>=n)right[x]=id[cur-n+1];
        for(int v:E[x]){
            if(!vis[v]){
                dfs(v);
            }
        }
        --cur;
    };
    for(int i=m;i>=1;--i){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i=m;i>=1;--i){
        right[i]=min(right[i],right[i+1]);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(right[l]<=r){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}   