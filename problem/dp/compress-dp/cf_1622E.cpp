#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node{
    int v,id;
};
void solve(){
  int n,m;
  cin>>n>>m;
  vector mp(1+n,vector<int>(m+1));
  vector<int>x(n+1);
  vector<string>correct(n+1);
  vector<int>p(n+1);
  vector<node>tmp(m+1);
  vector<int>ans_vec(m+1);
  for(int i=1;i<=n;++i){
    cin>>x[i];
  } 
  for(int i=1;i<=n;++i){
    cin>>correct[i];
    correct[i]='0'+correct[i];
    for(int j=1;j<=m;++j){
        if(correct[i][j]=='1'){
            mp[i][j]=1;
        }
    }
  }
  ll ans=-1;
  for(int msk=(1<<n)-1;msk>=0;--msk){
    for(int i=1;i<=m;++i){
        tmp[i].v=0;
        tmp[i].id=i;
    }
    ll now=0;
    for(int i=1;i<=n;++i){
        bool flag=(msk>>(i-1))&1;
        for(int j=1;j<=m;++j){
            tmp[j].v-=(flag?1:-1)*mp[i][j];
        }
        now+=(flag?1:-1)*x[i];
    }
    sort(tmp.begin()+1,tmp.end(),[&](node a,node b){
        return a.v<b.v;
    });
    for(int i=1;i<=m;++i){
        now+=tmp[i].v*i;
    }
    if(now>ans){
        ans=now;
        for(int i=1;i<=m;++i){
            ans_vec[tmp[i].id]=i;
        }
    }
  }
  for(int i=1;i<=m;++i){
    cout<<ans_vec[i]<<' ';
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
  int T;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}