#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+3),l(a),r(a);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    if(i>1){
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }else{
            l[i]=1;
        }
    }else{
        l[i]=1;
    }
  }
  for(int i=n;i>=1;--i){
    if(i==n){
        r[i]=1;
    }else{
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }else{
            r[i]=1;
        }
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i){
    ans=max(ans,max(l[i-1]+1,r[i+1]+1));
    if(a[i-1]+1<a[i+1]){
        ans=max(ans,l[i-1]+r[i+1]+1);
    }
  }
  cout<<ans<<'\n';
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