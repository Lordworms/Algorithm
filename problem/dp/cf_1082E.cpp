#include <bits/stdc++.h>
using namespace std;
using ll= long long;
const int MAXN=5e5+10;
const ll LIM=1e18;
map<int,int>last_mp;
int main(){
    int n,c;
    cin>>n>>c;
    vector<ll>pre(MAXN),cur_min(MAXN,LIM),sub_max(MAXN);
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        cur_min[a[i]]=min(cur_min[a[i]],pre[a[i]]-pre[c]);
        pre[a[i]]++;
        sub_max[a[i]]=max(sub_max[a[i]],pre[a[i]]-pre[c]-cur_min[a[i]]);
    }
    ll ans=-1;
    for(int i=1;i<=n;++i){
        ans=max(ans,sub_max[a[i]]+pre[c]);
    }
    cout<<ans<<'\n';
}