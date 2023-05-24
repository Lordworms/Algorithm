#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=10000;
void solve(){
  int n;cin>>n;
  vector<int>b(n+1);
  for(int i=1;i<=n;++i)cin>>b[i];
  vector<int>digit(N);
  int len=1;
  function<void(int)>find=[&](int dif){
    for(int i=1;dif;++i){
      if(i>len){
        len=i;
      }
      while(dif&&digit[i]<9){
        --dif;
        ++digit[i];
      }
    }
  };
  for(int i=1;i<=n;++i){
    int dif=b[i]-b[i-1];
    if(dif>0){
      find(dif);
    }else{
      for(int j=1;;++j){
        if(j>len)len=j;
        if(dif>0&&digit[j]<9){
          dif--;
          digit[j]++;
          find(dif);
          break;
        }
        dif+=digit[j];
        digit[j]=0;
      }
    }
    for(int j=len;j>=1;--j){
      cout<<digit[j];
    }
    cout<<'\n';
  }
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