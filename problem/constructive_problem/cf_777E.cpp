#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const int MOD=1e9+7;
struct node{
    int a,b,h;
    bool operator <(const node& aa)const{
        if(b==aa.b){
            return a>aa.a;
        }
        return b>aa.b;
    }
};
struct sta{
    int w,h;
    bool operator <(const sta& a)const{
        return h<a.h;//p should use opposite
    }
};
void solve(){
  int n;
  cin>>n;
  vector<node>arr(n+1);
  for(int i=1;i<=n;++i)cin>>arr[i].a>>arr[i].b>>arr[i].h;
  sort(arr.begin()+1,arr.end());
  priority_queue<sta>q;
  q.push({0,0});
  int ans=-1;
  for(int i=1;i<=n;++i){
    while(q.top().w>=arr[i].b){
        q.pop();
    }
    ans=max(ans,q.top().h+arr[i].h);
    q.push({arr[i].a,q.top().h+arr[i].h});
  }
  cout<<ans<<'\n';
  return;
}
signed main(){
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