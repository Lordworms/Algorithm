#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>fa(n+m+1);
    iota(fa.begin(),fa.end(),0);
    vector<vector<int>>E(n+m+1);
    vector<int>deg(n+m+1);
    function<int(int)>find=[&](int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    };
    function<void(int,int)>merge=[&](int x,int y){
        int fx=find(x),fy=find(y);
        fa[fy]=fx;
    };
    function<bool(int,int)>check=[&](int x,int y){
        return find(x)==find(y);
    };
    vector<string>mp(n+1);
    for(int i=1;i<=n;++i){
        cin>>mp[i];
        mp[i]='s'+mp[i];
        for(int j=1;j<=m;++j){
            char c=mp[i][j];
            if(c=='='){
                merge(i,j+n);
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            char c=mp[i][j];
            if(c=='<'){
                E[find(i)].push_back(find(j+n));
                deg[find(j+n)]++;
            }else if(c=='>'){
                E[find(j+n)].push_back(find(i));
                deg[find(i)]++;
            }
        }
    }
    queue<int>q;
    vector<ll>ans(n+m+1);
    int blocks=0,cur_blocks=0;
    for(int i=1;i<=n+m;++i){
        if(!deg[i]&&fa[i]==i){
            q.push(i); 
        }
        if(fa[i]==i)++blocks;
        if(!deg[i])ans[i]=1;
    }
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        ++cur_blocks;
        for(int v:E[x]){
            --deg[v];
            ans[v]=max(ans[v],ans[x]+1);
            if(!deg[v]){
                q.push(v);
                
            }
        }
    }
    if(cur_blocks!=blocks){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        for(int i=1;i<=n;++i){
            cout<<ans[find(i)]<<" \n"[i==n];
        }
        for(int i=n+1;i<=n+m;++i){
            cout<<ans[find(i)]<<" \n"[i==n+m];
        }
    }
    return 0;
}