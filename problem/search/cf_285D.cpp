#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
    vector<ll>a(17);
    a[1]=1;
    a[3]=3;
    a[5]=15;
    a[7]=133;
    a[9]=2025;
    a[11]=37851;
    a[13]=1030367;
    a[15]=36362925;
    vector<ll>fac(17);
    fac[0]=1;
    for(int i=1;i<fac.size();++i){
        fac[i]=(fac[i-1]*i%MOD);
    }
    int n;
    cin>>n;
    cout<<(a[n]*fac[n])%MOD<<'\n';
    return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}