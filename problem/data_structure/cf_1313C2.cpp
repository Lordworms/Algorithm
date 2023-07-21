#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n+2);
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<ll>s;
    vector<ll>L(n+2),R(n+2);
    s.push_back(0);
    for(int i=1;i<=n;++i){
      while(s.size()&&a[i]<a[s.back()])s.pop_back();
      L[i]=L[s.back()]+a[i]*(i-s.back());
      s.push_back(i);
    }
    s.clear();
    s.push_back(n+1);
    for(int i=n;i>=1;--i){
      while(s.size()&&a[i]<a[s.back()])s.pop_back();
      R[i]=R[s.back()]+a[i]*(s.back()-i);
      s.push_back(i);
    }
    ll res=-1,pos;
    for(int i=1;i<=n;++i){
      if(L[i]+R[i]-a[i]>res){
         pos=i;
         res=L[i]+R[i]-a[i];
      }
    }
    ll cur=a[pos];
    for(int i=pos;i>=1;--i){
      if(a[i]>cur){
         a[i]=cur;
      }else{
         cur=a[i];
      }
    }
    cur=a[pos];
    for(int i=pos;i<=n;++i){
      if(a[i]>cur){
         a[i]=cur;
      }else{
         cur=a[i];
      }
    }
    for(int i=1;i<=n;++i){
      cout<<a[i]<<" \n"[i==n];
    }
    return;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   #ifdef DEBUG
   freopen("/Users/yanxinxiang/code/Algorithm/in","r",stdin);
   freopen("/Users/yanxinxiang/code/Algorithm/out","w",stdout);
   #endif
   int T=1;
   while(T--){
      solve();
   }
   return 0;
}