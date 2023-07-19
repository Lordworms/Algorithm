#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF=1e18;
int main(){
    int n;
    ll k;
    cin>>n>>k;
    vector dp(n+1,vector<ll>(n+1));
    string s;
    cin>>s;
    s=')'+s;
    vector<int>last(26),pre(n+1);
    for(int i=1;i<=n;++i){
        int x=s[i]-'a';
        pre[i]=last[x];
        last[x]=i;
    }
    for(int i=0;i<=n;++i){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            if(pre[i])dp[i][j]-=dp[pre[i]-1][j-1];
        }
    }
    ll ans=0;
    for(int i=n;i>=0;--i){
       if(k>=dp[n][i]){
            ans+=1ll*(n-i)*dp[n][i];
            k-=dp[n][i];
       }else{
            ans+=1ll*(n-i)*k;
            k=0;
            break;
       }
    }
    if(k!=0){
        cout<<-1<<'\n';
    }else{
        cout<<ans<<'\n';
    }
}   