#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
using ll=long long;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=')'+s;
    vector dp(n+1,vector<ll>(n+1));
    for(int len=1;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r=l+len-1;
            if(r==l){
                dp[l][r]=1;
                continue;
            }
            ll cur_best=INF;
            for(int k=l;k<r;++k){
                if(s[k]==s[r]){
                    cur_best=min(cur_best,dp[l][k]+dp[k+1][r-1]);
                }else{
                    cur_best=min(cur_best,dp[l][k]+dp[k+1][r-1]+1);
                }
            }
            dp[l][r]=cur_best;
        }
    }
    cout<<dp[1][n]<<'\n';
}