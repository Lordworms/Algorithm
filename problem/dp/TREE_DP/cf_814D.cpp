#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
struct node{
    double x,y,r,s;
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>>E(n+1);
    vector<node>a(n+1);
    function<double(int i,int j)>dis=[&](int i,int j){
        return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
    };
    for(int i=1;i<=n;++i){
        cin>>a[i].x>>a[i].y>>a[i].r;
        a[i].s=pi*a[i].r*a[i].r;
    }
    sort(a.begin()+1,a.end(),[&](node a,node b){
        return a.r<b.r;
    });
    vector<int>fa(n+1,-1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(fa[j]==-1&&dis(i,j)<a[i].r+a[j].r){
                fa[j]=i;
                E[i].push_back(j);
            }
        }
    }
    double ans=0;
    function<void(int,int)>dfs=[&](int x,int t){
        for(int v:E[x]){
            if(t%2==0){
               ans+=a[v].s;  
            }else{
               ans-=a[v].s;
            }
            dfs(v,t^1);
        }
    };
    for(int i=1;i<=n;++i){
        if(fa[i]==-1){//it is a odd shit so we add the area
            ans+=a[i].s;
            dfs(i,0);
        }
    }
    cout.precision(10);
    cout<<ans<<'\n';
}