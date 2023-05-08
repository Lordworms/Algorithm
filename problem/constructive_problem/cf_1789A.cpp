#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  bool flag=false;
  for(int i=0;i<n;++i){
    for(int j=0;j<i;++j){
       if(gcd(a[i],a[j])<=2){
            flag=true;
            break;
       } 
    }
  }
  cout<<(flag?"YES":"NO")<<'\n';
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}