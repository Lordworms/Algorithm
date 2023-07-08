#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n+1,vector<int>(n+1));
    string s;
    auto parse_char=[&](int x,int y,char c){
        int num;
        if(isdigit(c)){
            num=c-'0';
        }else{
            num=c-'A'+10;
        }
        for(int j=1;j<=4;++j){
            a[x][y+4-j]=num&1;
            num>>=1;
        }
    };
    for(int i=1;i<=n;++i){
        cin>>s;
        for(int j=0;j<n/4;++j){
            parse_char(i,j*4+1,s[j]);
        }
    }
    int g=n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int k=j;
            while(k<=n&&a[i][j]==a[i][k])++k;
            g=gcd(g,k-j);
            j=k-1;
        }
    }
    for(int j=1;j<=n;++j){
        for(int i=1;i<=n;++i){
            int k=i;
            while(k<=n&&a[i][j]==a[k][j])++k;
            g=gcd(g,k-i);
            i=k-1;
        }
    }
    cout<<g<<'\n';
}