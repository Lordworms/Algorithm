#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector dp(n+1,vector<ll>(3));
    ll ans=0;
    for(int i=1;i<=n;++i){
        dp[i][0]=max(dp[i-1][0]+a[i],0ll);//不做
        dp[i][1]=max(dp[i][0],dp[i-1][1]+a[i]*x);//正在做
        dp[i][2]=max(dp[i][1],dp[i-1][2]+a[i]);//刚做完
        ans=max(ans,dp[i][2]);
    }
    cout<<ans<<'\n';
}