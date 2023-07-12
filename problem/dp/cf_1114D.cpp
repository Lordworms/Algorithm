#include <bits/stdc++.h>
using namespace std;
const int LIM=INT_MAX;
const int N=5e3+10;
int dp[N][N];
int a[N];
int num;
int main(){
    int n;
    cin>>n;
    int pre=-1;
    
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        if(x!=pre){
            a[++num]=x;
        }
        pre=x;
    }
    for(int len=1;len<=num;++len){
        for(int l=1;l+len<=num;++l){
            int r=l+len;
            if(a[l]==a[r]){
                dp[l][r]=dp[l+1][r-1]+1;
            }else{
                dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
            }
        }
    }
    cout<<dp[1][num]<<'\n';
}