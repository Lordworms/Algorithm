#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1e18;
int main(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s='&'+s;
    vector<int>pre(n+1),last(26);
    for(int i=1;i<=n;++i){
        int x=s[i]-'a';
        pre[i]=last[x];
        last[x]=i;
    }
    vector dp(n+1,vector<ll>(n+1));//number of distinct subsequence in [1,i] with length j
    for(int i=0;i<=n;++i){//starts from 0! important
        dp[i][0]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];//choose or not choose
            if(pre[i]){
                dp[i][j]-=dp[pre[i]-1][j-1];
            }
        }
    }
    ll ans=0;
    for(int i=n;i>=0;--i){
        if(k>=dp[n][i]){
            k-=dp[n][i];
            ans+=1ll*(n-i)*dp[n][i];
        }else{
            ans+=1ll*(n-i)*k;
            k=0;
            break;
        }
    }
    cout<<(k==0?ans:-1)<<'\n';
    return 0;
}