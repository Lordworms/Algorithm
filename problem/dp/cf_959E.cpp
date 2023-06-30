#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n;
    cin>>n;
    /*
        f(x)=f(x-1)+()
    */
    /*
        how to calculate the prefix sum of lowbit within log(n) time?
        well, we could think about such a situation that for every odd number within the range
        we must only add 1 to the ans, and then we right shift for 1 bit and then we found other 'odd' number in 'even' number
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