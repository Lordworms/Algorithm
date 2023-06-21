#include <bits/stdc++.h>%
using namespace std;
const int MAXN=2e3+10;
#define int long long
int a[MAXN],b[MAXN];
int n,k,p;
int dp[MAXN][MAXN];
int cost(int i,int j){
    return abs(a[i]-b[j])+abs(b[j]-p);
}
signed main(){
    cin>>n>>k>>p;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=k;++i)cin>>b[i];
    sort(b+1,b+1+k);
    for(int i=1;i<=n;++i){
        dp[i][i]=max(dp[i-1][i-1],cost(i,i));
        for(int j=i+1;j<=k-n+i;++j){
            dp[i][j]=min(dp[i][j-1],max(dp[i-1][j-1],cost(i,j)));
        }
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}