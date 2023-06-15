#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=1e8;
void solve(){
  int n,k,x;
  cin>>n>>k>>x;
  vector<int>maxx(k+1),minx(k+1);
  maxx[0]=-INF,minx[0]=INF;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    maxx[0]=max(maxx[0],a[i]);
    minx[0]=min(minx[0],a[i]);
  }
  auto check=[&](vector<int>&arr,int cur){
    return arr[cur]==arr[cur-1]&&arr[cur]==arr[cur-2]&&arr[cur]==arr[cur-3]&&arr[cur]==arr[cur-4];
  };
  for(int i=1;i<=k;++i){
    sort(a.begin()+1,a.end());
    maxx[i]=-INF;
    minx[i]=INF;
    for(int j=1;j<=n;++j){
        if(j&1){
            a[j]^=x;
        }
        maxx[i]=max(a[j],maxx[i]);
        minx[i]=min(a[j],minx[i]);
    }
    if(i>4&&check(maxx,i)&&check(minx,i)){
        cout<<maxx[i]<<' '<<minx[i]<<'\n';
        return;
    }
  }
  cout<<maxx.back()<<' '<<minx.back()<<'\n';
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