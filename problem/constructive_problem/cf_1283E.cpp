#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=2e5+10;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a.begin()+1,a.end());
  int maxans=n,minans=n;
  for(int i=1;i<=n;++i){
    for(int j=i+1;j<=n;++j){
        if(a[j]<=a[i]+2){
            --minans;
            if(j==n)i=j-1;
        }
        else{
            i=j-1;
            break;
        }
    }
  }
  vector<int>vis(N);
  for(int i=1;i<=n;++i){
    if(vis[a[i]-1]==0){
        vis[a[i]-1]=1;
    }
    else if(vis[a[i]]==0){
        vis[a[i]]=1;
    }
    else if(vis[a[i]+1]==0){
        vis[a[i]+1]=1;
    }else{
        --maxans;
    }
  }
  cout<<minans<<' '<<maxans<<'\n';
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