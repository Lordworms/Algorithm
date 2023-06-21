#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>pro,peo;
    for(int i=0;i<s.size();++i){
        if(s[i]=='*'){
            pro.push_back(i);
        }
        if(s[i]=='P'){
            peo.push_back(i);
        }
    }
    function<int(int,int,int)>cal=[&](int l,int r,int cur){
        return min(abs(r-cur),abs(cur-l))+abs(r-l);
    };
    function<bool(int)>check=[&](int time){
        int pre=0,cur=0;
        for(int p:peo){
            while(cur<pro.size()&&cal(pro[pre],pro[cur],p)<=time)++cur;
            pre=cur;
        }
        return cur==pro.size();
    };
    int l=0,r=2*n,ans=-1;
    while(l<=r){
        int m=(l+r)>>1;
        if(check(m)){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<ans<<'\n';
}