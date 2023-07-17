#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
using ll=long long;
int main(){
    int n;
    cin>>n;
    ll ans=n;
    vector<ll>deg(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        deg[v]++;
        deg[u]++;
        ans=ans*deg[u]%MOD*deg[v]%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}