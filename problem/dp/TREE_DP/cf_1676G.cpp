#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>f(n+1);
  vector<vector<int>>E(n+1);
  for(int i=2;i<=n;++i){
    cin>>f[i];
    if(f[i]!=i){
        E[f[i]].push_back(i);
    }
  }
  string color;
  cin>>color;
  color='0'+color;
  vector<int>white(n+1),black(n+1);
  function<void(int,int)>dfs=[&](int x,int fa){
    if(color[x]=='W'){
        white[x]++;
    }else{
        black[x]++;
    }
    for(auto v:E[x]){
        if(v!=fa){
            dfs(v,fa);
            white[x]+=white[v];
            black[x]+=black[v];
        }
    }
  };
  dfs(1,-1);
  int ans=0;
  for(int i=1;i<=n;++i){
    if(white[i]==black[i]){
        ++ans;
    }
  }
  cout<<ans<<'\n';
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