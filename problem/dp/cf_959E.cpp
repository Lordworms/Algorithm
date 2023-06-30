#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n;
    cin>>n;
    /*
        f(x)=f(x-1)+()
    */
    ll ans=0,base=1;
    while(n>1){
        ans+=base*(n>>1);
        n-=(n>>1);
        base<<=1;
    }
    cout<<ans<<'\n';
    return 0;
}