#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=20;
const int MAXB=5;
ll dp[MAXN][MAXB];
ll a[MAXN];
ll dfs(int pos,int st,bool flag){
    if(pos==-1)return 1;
    if(dp[pos][st]!=-1&&!flag)return dp[pos][st];
    int lim=flag?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=lim;++i){
        if(i==0){
            ans+=dfs(pos-1,st,flag&&a[pos]==i);
        }else if(st!=3){
            ans+=dfs(pos-1,st+1,flag&&a[pos]==i);
        }
    }
    if(!flag)dp[pos][st]=ans;
    return ans;
}
ll cal(ll x){
    int len=0;
    while(x){
        a[len++]=x%10;
        x/=10;
    }
    return dfs(len-1,0,true);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int T;
    cin>>T;
    while(T--){
        ll l,r;
        cin>>l>>r;
        cout<<cal(r)-cal(l-1)<<'\n';
    }
}