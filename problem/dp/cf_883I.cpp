/*
I. Photo Processing
Evlampiy has found one more cool application to process photos. However the application has certain limitations.

Each photo i has a contrast vi. In order for the processing to be truly of high quality, the application must receive at least k photos with contrasts which differ as little as possible.

Evlampiy already knows the contrast vi for each of his n photos. Now he wants to split the photos into groups, so that each group contains at least k photos. As a result, each photo must belong to exactly one group.

He considers a processing time of the j-th group to be the difference between the maximum and minimum values of vi in the group. Because of multithreading the processing time of a division into groups is the maximum processing time among all groups.

Split n photos into groups in a such way that the processing time of the division is the minimum possible, i.e. that the the maximum processing time over all groups as least as possible.

5 2
50 110 130 40 120

*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vector<int>dp(n+1);
    dp[0]=1;
    function<bool(int)>check=[&](int v){
        int l=1,r;
        for(int i=1;i<=n;++i){
            dp[i]=0;
            while(a[i]-a[l]>v)++l;
            r=i-k+1;
            for(int j=l;j<=r;++j,++l){
                if(dp[j-1]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n]==1;
    };
    int l=0,r=a.back()-a[1],ans=0;
    while(l<=r){
        int m=(l+r)>>1;
        if(check(m)){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<ans<<'\n';
}