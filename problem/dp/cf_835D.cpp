#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    s=')'+s;
    vector dp(n+1,vector<int>(n+1));
    vector<int>ans(n+1);
    for(int i=1;i<=n;++i){
        dp[i][i]=1;
        ans[1]++;
    }
    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r=l+len-1;
            if(s[l]!=s[r]||l+1<=r-1&&dp[l+1][r-1]==0){
                dp[l][r]=0;
            }else if(s[l]==s[r]){
                dp[l][r]=dp[l][l+len/2-1]+1;
            }
            if(dp[l][r]>0){
                ans[dp[l][r]]++;
            }
        }
    }
    for(int i=n-1;i>=1;--i){
        ans[i]+=ans[i+1];
    }
    for(int i=1;i<=n;++i){
        cout<<ans[i]<<" \n"[i==n];
    }
    return 0;
}