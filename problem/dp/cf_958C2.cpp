#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k,p;
    cin>>n>>k>>p;
    vector<ll>a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]=(a[i]+a[i-1])%p;
    }
    vector dp(p+1,vector<ll>(n+1,-1e18));
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=k;j>=1;--j){
            for(int mod=0;mod<p;++mod){
                dp[a[i]][j]=max(dp[a[i]][j],dp[mod][j-1]+(a[i]-mod+p)%p);
            }
        }
    }
    cout<<dp[a[n]][k]<<'\n';
}