#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
const int N=5005;
int a[N],g[N];
int gcd(int a,int b){
  return b==0 ? a : gcd(b,a%b);
}
set<int>bad;
pii get_pair(int x){
    int posi=0,neg=0;
    for(int i=2,t=sqrt(x);i<=t;++i){
        int cnt=0;
        while(x%i==0){
            x/=i;
            ++cnt;
        }
        if(!cnt)continue;
        if(bad.count(i)){
            neg+=cnt;
        }else{
            posi+=cnt;
        }
    }
    if(x!=1){
        if(bad.count(x)){
            neg++;
        }else{
            posi++;
        }
    }
    return pii(posi,neg);
};
bool check(int x){
    pii pr=get_pair(x);
    return pr.first<pr.second;
}
void solve(){
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    if(i==1){
        g[i]=a[i];
    }else{
        g[i]=gcd(a[i],g[i-1]);
    }
  }
  for(int i=1;i<=m;++i){
    int x;cin>>x;
    bad.insert(x);
  }
  
  int ans=0,d=1;
  for(int i=n;i>=1;--i){
    if(check(g[i]/d)){
        d=g[i];
    }
    a[i]/=d;
  }
  for(int i=1;i<=n;++i){
    pii pr=get_pair(a[i]);
    ans+=pr.first-pr.second;
  }
  cout<<ans<<'\n';
  return;
}
int main(){
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}