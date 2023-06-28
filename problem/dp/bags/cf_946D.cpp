#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<string>days(n+1);
    vector<int>cnt(n+1);
    vector<vector<int>>dp(n+1,vector<int>(k+1,INF));
    vector<vector<int>>skip(n+1,vector<int>(m+1,INF));
    for(int i=1;i<=n;++i){
        cin>>days[i];
        days[i]=')'+days[i];
        vector<int>pos(m+1);
        for(int j=1;j<days[i].size();++j){
            if(days[i][j]=='1'){
                pos[++cnt[i]]=j;
            }
        }
        skip[i][cnt[i]]=0;
        for(int len=1;len<=cnt[i];++len){
            for(int l=1;l+len-1<=cnt[i];++l){
                int r=l+len-1;
                skip[i][cnt[i]-len]=min(skip[i][cnt[i]-len],pos[r]-pos[l]+1);//the minimal time you need to stay at schoool if you skip cnt[i]-len class
            }
        }
    }
    for(int i=0;i<=k;++i){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            for(int sk=0;sk<=min(j,cnt[i]);++sk){
                dp[i][j]=min(dp[i][j],dp[i-1][j-sk]+skip[i][sk]);
            }
        }
    }
    cout<<dp[n][k]<<'\n';
}