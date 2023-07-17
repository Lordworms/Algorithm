#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1e18;
const int MAXN=3e5+10;
ll a[MAXN],b[MAXN];
ll dp[MAXN][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    memset(dp,0x3f,sizeof(dp));
    while(q--){
        int n;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i]>>b[i];
        }
        for(int i=0;i<=n;++i)dp[i][0]=dp[i][1]=dp[i][2]=INF;
        dp[0][0]=0;
        for(int i=1;i<=n;++i){
            for(int k1=0;k1<3;++k1){
                for(int k2=0;k2<3;++k2){
                    if(a[i-1]+k2!=a[i]+k1){
                        dp[i][k1]=min(dp[i][k1],dp[i-1][k2]+b[i]*k1);
                    }
                }
            }
        }
        ll ans=INF;
        for(int i=0;i<3;++i){
            ans=min(ans,dp[n][i]);
        }
        cout<<ans<<'\n';
    }
}