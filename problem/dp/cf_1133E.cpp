#include <bits/stdc++.h>
using namespace std;
const int LIM=5;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a.begin()+1,a.end());
    vector<int>cnt(n+1);
    vector dp(n+1,vector<int>(n+1));
    int pos=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            while(pos<=i&&a[i]-a[pos]>5)++pos;
            dp[i][j]=max(dp[i-1][j],dp[pos-1][j-1]+(i-pos+1));
        }
    }
    int ans=0;
    for(int i=1;i<=n&&i<=k;++i){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<'\n';
}