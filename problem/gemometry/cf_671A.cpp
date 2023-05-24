#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  double ax,ay,bx,by,tx,ty;
  cin>>ax>>ay>>bx>>by>>tx>>ty;
  int n;
  cin>>n;
  auto dis=[&](double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  };
  double justA=1e16,justB=1e16,justAB=1e16,sum=0;
  for(int i=1;i<=n;++i){
      double x,y;
      cin>>x>>y;
      auto dt=dis(tx,ty,x,y);
      auto da=dis(ax,ay,x,y)-dt;
      auto db=dis(bx,by,x,y)-dt;
      sum+=2*dt;
      justAB=min(justAB,min(justA+db,justB+da));
      justA=min(justA,da);
      justB=min(justB,db);
  }
  cout.precision(10);
  cout<<sum+std::min({justA,justB,justAB})<<'\n';
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