#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct group{
    int c,p,id;
};
struct table{
    int cap,id;
};
void solve(){
  int n;
  cin>>n;
  vector<group>arr(n);
  for(int i=0;i<n;++i){
    cin>>arr[i].c>>arr[i].p;
    arr[i].id=i;
  }
  int k;
  cin>>k;
  vector<table>r(k);
  for(int i=0;i<k;++i){
    cin>>r[i].cap;
    r[i].id=i;
  }
  sort(r.begin(),r.end(),[&](table a,table b){
    return a.cap<b.cap;
  });
  sort(arr.begin(),arr.end(),[&](group a ,group b){
    return a.p>b.p;
  });
  ll ans=0;
  vector<bool>used(k);
  vector<pair<int,int>>trace;
  for(int i=0;i<n;++i){
    for(int j=0;j<k;++j){
        if(!used[j]&&r[j].cap>=arr[i].c){
            ans+=arr[i].p;
            used[j]=1;
            trace.push_back({arr[i].id+1,r[j].id+1});
            break;
        }
    }
  }
  cout<<trace.size()<<' '<<ans<<'\n';
  for(auto& k:trace){
    cout<<k.first<<' '<<k.second<<'\n';
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