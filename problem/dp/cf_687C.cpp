#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  vector dp(k+1,vector<int>(k+1));
  dp[0][0]=1;
  for(int i=0;i<=n;++i){
    for(int v1=k;v1>=0;--v1){
        for(int v2=k;v2>=0;--v2){
            if(dp[v1][v2]&&v1+a[i]<=k){
                dp[v1+a[i]][v2]=dp[v1+a[i]][v2+a[i]]=1;
            }
        }
    }
  }
  vector<int>ans;
  for(int i=0;i<=k;++i){
    if(dp[k][i]){
        ans.push_back(i);
    }
  }
  cout<<ans.size()<<'\n';
  for(int i=0;i<ans.size();++i){
    cout<<ans[i]<<" \n"[i==ans.size()-1];
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