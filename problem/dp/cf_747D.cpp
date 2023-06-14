#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1);
  vector<int>snow_range;
  int last_snow=-1;
  int ans=0;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    if(a[i]<0){
        if(last_snow>0)snow_range.push_back(i-last_snow-1);
        last_snow=i;
        ans+=2;
        --k;
    }
  }
  if(k<0){
    cout<<-1<<'\n';
    return;
  }
  sort(snow_range.begin(),snow_range.end());
  for(int r:snow_range){
    if(k>=r){
        k-=r;
        ans-=2;
    }else{
        break;
    }
  }
  cout<<(n-last_snow<=k?ans-1:ans)<<'\n';
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