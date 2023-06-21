#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e3+10;
int main(){
    int n;
    cin>>n;
    vector<int>p(n+1),total(MAXN),maxx(n+1);
    for(int i=1;i<=n;++i){
        cin>>p[i];
        total[p[i]]++;
    }
    int ans=INT_MIN;
    vector<int>dp(n+1);
    for(int i=1;i<=n;++i){
        int valid=0;
        int x_sum=0;
        vector<int>cnt(MAXN);
        for(int j=i;j>=1;--j){
            if(!cnt[p[j]]){
                valid++;
                x_sum^=p[j];
            }
            cnt[p[j]]++;
            if(cnt[p[j]]==total[p[j]])--valid;
            if(!valid)dp[i]=max(dp[i],maxx[j-1]+x_sum);
        }
        maxx[i]=max(maxx[i-1],dp[i]);
    }
    cout<<maxx[n]<<'\n';
}