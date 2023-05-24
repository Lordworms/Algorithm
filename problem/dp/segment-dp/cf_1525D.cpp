#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
void solve(){
  int n;
  cin>>n;
  vector<int>pos={0},neg={0};
  vector dp(n+1,vector<ll>(n+1,INF));//dp[i][j] means i positive and j negative
  for(int i=1;i<=n;++i){
    dp[0][i]=0;
    int x;
    cin>>x;
    if(x>0){
      pos.push_back(i);
    }else{
      neg.push_back(i);
    }
  }
  dp[0][0]=0;
  for(int i=1;i<pos.size();++i){
    for(int j=1;j<neg.size();++j){
      dp[i][j]=min(dp[i-1][j-1]+abs(pos[i]-neg[j]),dp[i][j-1]);
    }
  }
  cout<<dp[pos.size()-1][neg.size()-1]<<"\n";
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