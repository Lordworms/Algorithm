#include <bits/stdc++.h>
using namespace std;
const int MAXN=7010;
bool dp[2][MAXN];//current in position i, its j's turn
int sets[2][MAXN];
int k[2];
int n;
bool vis[2][MAXN];
int cnt[2][MAXN];
void dfs(int p,int pos){
    if(vis[p][pos])return;
    vis[p][pos]=1;
    int q=p^1;
    for(int i=1;i<=k[q];++i){
        int pre_pos=(pos-sets[q][i]+n-1)%n+1;
        if(pre_pos==1)continue;
        if(!dp[p][pos]){
            dp[q][pre_pos]=1;
            dfs(q,pre_pos);
        }else if(++cnt[q][pre_pos]==k[q]){
            dp[q][pre_pos]=0;
            dfs(q,pre_pos);
        }
    }
}
int main(){
    #ifdef DEBUG
        freopen("in","r",stdin);
        freopen("out","w",stdout);
    #endif
    cin>>n;
    for(int i=0;i<2;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>sets[i][j];
        }
    }
    dfs(0,1);
    dfs(1,1);
    for(int i=0;i<2;++i){
        for(int j=2;j<=n;++j){
            cout<<(vis[i][j]?dp[i][j]?"Win":"Lose":"Loop")<<" \n"[j==n];
        }
    }
    return 0;
}