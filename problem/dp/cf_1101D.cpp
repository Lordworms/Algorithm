#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<vector<int>>fac(n+1),dp(fac);
    bool flag=false;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        int x=a[i];
        for(int j=2;j*j<=x;++j){
            if(x%j==0){
                fac[i].push_back(j);
                dp[i].push_back(1);
                while(x%j==0){
                    x/=j;
                }
            } 
        }
        if(x>1){
            fac[i].push_back(x);
            dp[i].push_back(1);
        }
        flag=(a[i]>1);
    }
    if(!flag){
        cout<<0<<'\n';
        return 0;
    }
    vector<vector<int>>E(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int ans=1;
    function<void(int,int)>dfs=[&](int x,int f){
        for(int v:E[x]){
            if(v==f)continue;
            dfs(v,x);
            for(int i=0;i<fac[x].size();++i){
                for(int j=0;j<fac[v].size();++j){
                    if(fac[x][i]==fac[v][j]){
                        ans=max(ans,dp[x][i]+dp[v][j]);
                        dp[x][i]=max(dp[x][i],dp[v][j]+1);
                    }
                }
            }
        }
    };
    dfs(1,0);
    cout<<ans<<'\n';
}