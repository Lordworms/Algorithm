#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int>a(n+1);
    ll sum=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    vector<int>Q(n+5);
    int l=1,r=0;
    vector<ll>dp(n+1);
    for(int i=1;i<=n;++i){
        while(l<=r&&a[Q[r]]>=a[i]){
            r--;
        }
        Q[++r]=i;
        while(l<=r&&Q[l]<=i-c)++l;
        if(i>=c){
            dp[i]=max(dp[i-1],dp[i-c]+a[Q[l]]);
        }
    }
    cout<<sum-dp[n]<<'\n';
}