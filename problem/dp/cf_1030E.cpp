#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int ans=0;
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i){
        long long x;
        cin>>x;
        a[i]=__builtin_popcountll(x);
    }
    int suf=0;
    vector<int>cnt={1,0};
    for(int l=n;l>=1;--l){
        suf+=a[l];
        ans+=cnt[suf%2];
        int max_one=0,total_one=0;
        for(int r=l;r<=min(n,l+65);++r){
            max_one=max(max_one,a[r]);
            total_one+=a[r];
            ans-=total_one%2==0&&total_one<2*max_one;
        }
        cnt[suf%2]++;
    }
    cout<<ans<<'\n';
}