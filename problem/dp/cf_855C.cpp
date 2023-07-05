#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=1e5+5;
const int K=15;
using ll=long long;
int dp[N][K][3];//dp[i][j][k] means using j colors in i's subtrees and k=0/1/2 indicates the current one is less/equal/greater than k
int cur[N][K];
int main(){
    int n,m,k,X;
    cin>>n>>m;
    vector<vector<int>>E(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    cin>>k>>X;
    vector<int>sz(n+1);
    function<void(int,int)>dfs=[&](int x,int f){
        sz[x]=1;
        dp[x][0][0]=k-1;
        dp[x][1][1]=1;
        dp[x][0][2]=m-k;
        for(int v:E[x]){
            if(v==f)continue;
            dfs(v,x);
            int lim1=min(sz[x],X),lim2;
            for(int i=0;i<=lim1;++i){
                for(int j=0;j<=2;++j){
                    cur[i][j]=dp[x][i][j];
                    dp[x][i][j]=0;
                }
            }
            for(int i=0;i<=lim1;++i){
                lim2=min(X-i,sz[v]);
                for(int j=0;j<=lim2;++j){
                    dp[x][i+j][0]=(dp[x][i+j][0]+(1ll*cur[i][0]*((dp[v][j][0]+dp[v][j][1])%MOD+dp[v][j][2])%MOD))%MOD;
                    dp[x][i+j][1]=(dp[x][i+j][1]+(1ll*cur[i][1]*((dp[v][j][0]))%MOD))%MOD;
                    dp[x][i+j][2]=(dp[x][i+j][2]+(1ll*cur[i][2]*((dp[v][j][0]+dp[v][j][2]))%MOD)%MOD)%MOD;
                }
            }
            sz[x]+=sz[v];
        }
    };
    dfs(1,0);
    ll ans=0;
    for(int i=0;i<=X;++i){
        for(int j=0;j<=2;++j){
            ans=(ans+dp[1][i][j])%MOD;
        }
    }
    cout<<ans<<'\n';
}