#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  function<int(int,int)>paint=[&](int l,int r){
    int k=l;
    if(r<l)return 0;
    for(int i=l;i<=r;++i){
        if(a[i]<=a[k]){
            k=i;
        }
    }
    int subtract=a[k];
    for(int i=l;i<=r;++i){
        a[i]-=subtract;
    }
    return min(r-l+1,paint(l,k-1)+paint(k+1,r)+subtract);
  };
  cout<<paint(0,n-1)<<'\n';
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