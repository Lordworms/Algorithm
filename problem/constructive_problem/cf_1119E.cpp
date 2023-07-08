#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<int>a(n+2);
    for(int i=1;i<=n;++i)cin>>a[i];
    int cur=1;
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=(a[i]/3);
        a[i]%=3;
        if(cur<=i)cur=i+1;
        while(cur<=n&&a[cur]<2)++cur;
        if(a[i]>=1&&a[cur]>=2){
            ans++;
            a[cur]-=2;
            a[i]--;
        }
        while(cur<=n&&a[cur]<2)++cur;
        if(a[i]>=1&&a[cur]>=2){
            ans++;
            a[cur]-=2;
            a[i]--;
        }
    }
    cout<<ans<<'\n';
}