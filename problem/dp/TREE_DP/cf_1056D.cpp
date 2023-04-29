#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n; 
  vector<int>num(n+1);
  vector<vector<int>>E(n+1);
  for(int i=2;i<=n;++i){
    int p;
    cin>>p;
    E[p].push_back(i);
  }
  function<void(int,int)>dfs=[&](int x,int f){
    if(E[x].size()==0){
        num[x]=1;
        return;
    }
    for(int v:E[x]){
        dfs(v,x);
        num[x]+=num[v];
    }
  };
  dfs(1,0);
  sort(num.begin()+1,num.end());
  for(int i=1;i<=n;++i){
    cout<<num[i]<<" \n"[i==n];
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