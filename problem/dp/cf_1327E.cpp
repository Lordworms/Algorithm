#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<ll>pw(n+1);
    pw[1]=10;
    for(int i=2;i<=n;++i){
        pw[i]=10*pw[i-1]%MOD;
    }
    for(int i=1;i<=n;++i){
        if(i==n){
            cout<<"10\n";
        }else{
            cout<<(18*pw[n-i]%MOD+(n-i-1)*81*pw[n-i-1]%MOD)%MOD<<" ";
        }
    }
    return 0;
}