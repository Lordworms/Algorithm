#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=1e6+5;
char b[maxm];
char n[maxm];
int c;
int ppow(int a,int b,int mod){
    int ans=1%mod;a%=mod;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n!=1)ans=ans/n*(n-1);
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin>>b>>n>>c;
    int lenb=strlen(b);
    int lenn=strlen(n);
    //底数b%c
    int base=0;
    for(int i=0;i<lenb;i++){
        base=(base*10+b[i]-'0')%c;
    }
    //指数
    for(int i=lenn-1;i>=0;i--){
        n[i]--;
        if(n[i]<0){
            n[i]+=10;
            n[i-1]--;
        }else{
            break;
        }
    }
    int phi1=phi(c);
    int p=0;
    int f=0;
    for(int i=0;i<lenn;i++){
        p=p*10+n[i]-'0';
        if(p>=phi1)f=1;
        p%=phi1;
    }
    if(f)p+=phi1;
    //
    int ans=(base-1)*ppow(base,p,c)%c;
    ans=(ans%c+c)%c;
    if(ans)cout<<ans<<endl;
    else cout<<c<<endl;
    return 0;
}
