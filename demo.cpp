#include <bits/stdc++.h>
using namespace std;

const int maxn=5e2+10;
int a[maxn]={0};
int dp[2][maxn][maxn]={0};
///第二维表示到了第几轮
///
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        memset(dp[i%2],-1, sizeof (dp[i%2]));
        for(int j=0;j<i;j++){
            for(int k=max(0,i-(j+1)-1);k<=j;k++){
                if(dp[(i+1)%2][j][k]==-1)continue;
                dp[i%2][j+1][k-(i-(j+1))+1]=max( dp[i%2][j+1][k-(i-(j+1))+1],dp[(i+1)%2][j][k]+a[i]);
                ///
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=0;k<=j;k++){
                if(dp[i%2][j-1][k]==-1)continue;
                dp[i%2][j][k]=max(dp[i%2][j][k],dp[i%2][j-1][k]+a[i]);
            }
        }
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++){
                dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i+1)%2][j][k]);
            }
                    }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[n%2][n][i]);
    }
    cout<<ans;
}