#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    bool pos_flag=false,neg_flag=false;
    int minimal=INT_MAX;
    long long ans=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(n==1){
            cout<<a[1]<<'\n';
            return 0;
        }
        pos_flag|=(a[i]>=0);
        neg_flag|=(a[i]<=0);
        minimal=min(minimal,abs(a[i]));
        ans+=abs(a[i]);
    }
    if(pos_flag&&neg_flag){
        cout<<ans<<'\n';
    }else{
        cout<<ans-2*minimal<<'\n';
    }
    return 0;
}