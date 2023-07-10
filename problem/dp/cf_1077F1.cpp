#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1e18));
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=min(x,i);++j){
            for(int p=max(0,i-k);p<=i-1;++p){
                dp[i][j]=max(dp[i][j],dp[p][j-1]+a[i]);
            }
        }
    }
    ll ans=-1e18;
    for(int i=n;i>max(0,n-k);--i){
        ans=max(ans,dp[i][x]);
    }
    if(ans<0){
        cout<<-1<<'\n';
        return 0;
    }
    cout<<ans<<'\n';
}