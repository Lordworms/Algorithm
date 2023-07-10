#include <bits/stdc++.h>
using namespace std;
using ll=long long;
map<int,int>card_cnt;
map<int,int>love_cnt;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n*k;++i){
        int x;
        cin>>x;
        card_cnt[x]++;
    }
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        love_cnt[x]++;
    }
    vector<int>h(k+1);
    for(int i=1;i<=k;++i)cin>>h[i];
    ll ans=0;
    for(auto& kk:card_cnt){
        vector<ll>dp(n*k+1);
        if(kk.second==0||love_cnt.find(kk.first)==love_cnt.end())continue;
        int num=kk.second;
        for(int i=1;i<=love_cnt[kk.first];++i){
            for(int j=kk.second;j>=1;--j){
                for(int t=0;t<=min(j,k);++t){
                    dp[j]=max(dp[j],dp[j-t]+h[t]);
                }
            }
        }
        ans+=dp[kk.second];
        kk.second=0;
    }
    cout<<ans<<'\n';
}