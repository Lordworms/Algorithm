#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
signed main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    vector<int>maxx(n+1);
    int l=1,r=0;
    for(int i=1;i<=n;++i){
        while(l<=r&&a[i]>a[maxx[r]])--r;
        maxx[++r]=i;
    }
    int ans1,ans2,ans3,ans=0;
    int si=0,sj,sk=0;
    for(int j=0;j<=n;++j){
        if(maxx[l]<j){
            ++l;
        }
        sk=maxx[l];
        if(a[si]<a[j]){
            si=j;
        }
        if(a[si]+a[sk]-a[j]>=ans){
            ans=a[si]+a[sk]-a[j];
            ans1=si,ans2=j,ans3=sk;
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3<<'\n';
}