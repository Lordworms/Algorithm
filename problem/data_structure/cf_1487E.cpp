#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  vector<int>n(5);
  vector<int>m(5);
  vector<vector<ll>>dish(5,vector<ll>());
  vector E(5,vector<vector<int>>());
  for(int i=1;i<=4;++i){
    cin>>n[i];
  }
  for(int i=1;i<=4;++i){
    dish[i].resize(n[i]+1);
    for(int j=1;j<dish[i].size();++j){
        cin>>dish[i][j];
    }
  }
  for(int i=2;i<=4;++i){
    cin>>m[i];
    E[i].resize(n[i]+1);
    for(int j=0;j<m[i];++j){
        int x,y;cin>>x>>y;
        E[i][y].push_back(x);
    }
  }
  vector<multiset<ll>>st(6);
  for(int i=1;i<=n[1];++i){
    st[2].insert(dish[1][i]);
  }
  for(int i=2;i<=4;++i){
    for(int j=1;j<=n[i];++j){
        for(int v:E[i][j]){
            st[i].erase(st[i].find(dish[i-1][v]));
        }
        if(!st[i].empty()){
            dish[i][j]+=*st[i].begin();
        }
        else{
            dish[i][j]=1e13;
        }
        st[i+1].insert(dish[i][j]);
        for(int v:E[i][j]){
            st[i].insert(dish[i-1][v]);
        }
    }
  }
  if(!st[5].empty()&&*st[5].begin()<1e13){
    cout<<*st[5].begin()<<'\n';
  }
  else{
    cout<<-1<<'\n';
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