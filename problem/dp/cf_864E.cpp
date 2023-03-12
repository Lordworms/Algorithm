#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node{
    int t,d,v,id;
};
void solve(){
  int n;cin>>n;
  vector<node>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i].t>>a[i].d>>a[i].v;
    a[i].id=i;
  }
  sort(a.begin()+1,a.end(),[&](node a,node b){
    return a.d<b.d;
  });
  vector<vector<int>>st(2001);
  vector<int>dp(2001);
  for(int i=1;i<=n;++i){
    int d=a[i].d,v=a[i].v,id=a[i].id,t=a[i].t;
    for(int j=d-1;j>=t;--j){
        if(dp[j]<dp[j-t]+v){
            dp[j]=dp[j-t]+v;
            st[j]=st[j-t];
            st[j].push_back(id);
        }
    }
  }
  int ans=0;
  for(int i=0;i<=2000;++i){
    if(dp[i]>dp[ans]){
        ans=i;
    }
  }
  cout<<dp[ans]<<'\n';
  cout<<st[ans].size()<<'\n';
  for(int i=0;i<st[ans].size();++i){
    cout<<st[ans][i]<<' ';
  }
  cout<<'\n';
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