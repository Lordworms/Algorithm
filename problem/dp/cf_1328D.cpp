#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],c[N];
int main(){
    // freopen("/Users/yanxinxiang/code/Algorithm/in","r",stdin);
    // freopen("/Users/yanxinxiang/code/Algorithm/out","w",stdout);
    int q,n;
    cin>>q;
    
    while(q--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        a[n+1]=a[1];
        bool f1=false,f2=false;
        int x=-1;
        for(int i=1;i<=n;++i){
            if(a[i]==a[i+1]){
                f1=true;
                x=i;
            }else{
                f2=true;
            }
        }
        if(!f2){
            cout<<1<<'\n';
            for(int i=1;i<=n;++i){
                cout<<1<<" \n"[i==n];
            }
        }
        else {
            if(n%2==0){
                cout<<2<<'\n';
                for(int i=1;i<=n;++i){
                    cout<<((i%2)?1:2)<<" \n"[i==n];
                }
            }else if(f1){//至少有一对相邻的相同，断开后交替染色
                cout<<2<<'\n';
                for(int i=1;i<=n;++i){
                    c[(x+i-1)%n+1]=i&1;
                }
                for(int i=1;i<=n;++i){
                    cout<<c[i]+1<<" \n"[i==n];
                }
            }else{
                cout<<3<<'\n';
                for(int i=1;i<=n-1;++i){
                    cout<<((i&1)+1)<<' ';
                }
                cout<<3<<'\n';
            }
        }
    }
    return 0;
}