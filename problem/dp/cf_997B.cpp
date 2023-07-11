#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long ans=0;
    for(int i=0;i<=min(8,n);++i){
        for(int j=0;i+j<=n&&j<=(i==0?8:4);++j){
            ans+=n-i-j+1;
        }
    }
    cout<<ans<<'\n';
}